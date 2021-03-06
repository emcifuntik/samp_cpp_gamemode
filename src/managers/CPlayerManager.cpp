#include "stdafx.h"

bool CPlayerManager::Connect(int playerid)
{
  if (playerid > maxID)
    maxID = playerid;

  this->playersPool[playerid] = new CPlayer(playerid);
  for (auto it = this->connectHandlers.begin(); it < this->connectHandlers.end(); ++it) {
    if ((*it)(this->playersPool[playerid])) {
      return true;
    }
  }
  return false;
}
bool CPlayerManager::OnConnect(std::function<bool(CPlayer*)> callback)
{
	this->connectHandlers.push_back(callback);
	return true;
}

bool CPlayerManager::Spawn(int playerid)
{
  for (auto it = this->spawnHandlers.begin(); it < this->spawnHandlers.end(); ++it) {
    if ((*it)(this->playersPool[playerid])) {
      return true;
    }
  }
  return true;
}
bool CPlayerManager::OnSpawn(std::function<bool(CPlayer*)> callback)
{
	this->spawnHandlers.push_back(callback);
	return true;
}

bool CPlayerManager::Disconnect(int playerid, int reason)
{
  if (playerid == maxID) {
    for (int i = maxID - 1; i >= 0; --i) {
      if (this->IsConnected(i))
      {
        maxID = i;
        break;
      }
    }
    if (playerid == maxID)
      maxID = 0;
  }
  for (auto it = this->disconnectHandlers.begin(); it < this->disconnectHandlers.end(); ++it) {
    if ((*it)(this->playersPool[playerid], reason)) {
      return true;
    }
  }
  delete this->playersPool[playerid];
  this->playersPool[playerid] = nullptr;
  return true;
}
bool CPlayerManager::OnDisconnect(std::function<bool(CPlayer*, int reason)> callback)
{
	this->disconnectHandlers.push_back(callback);
	return true;
}


PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerSpawn(int playerid) {
	return CPlayerManager::get().Spawn(playerid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerDisconnect(int playerid, int reason) {
	return CPlayerManager::get().Disconnect(playerid, reason);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerConnect(int playerid) {
	CPlayer * player = CPlayerManager::get()[playerid];
	CPlayerManager::get().Connect(playerid);
	return true;
}
