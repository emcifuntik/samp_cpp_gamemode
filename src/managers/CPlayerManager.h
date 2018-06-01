#pragma once

class CPlayerManager: public CSingleton<CPlayerManager>
{
  CPlayer * playersPool[1000] = { nullptr };
  int maxID = 0;

  std::vector<std::function<bool(CPlayer*)>> connectHandlers;
  std::vector<std::function<bool(CPlayer*)>> spawnHandlers;
  std::vector<std::function<bool(CPlayer*, int)>> disconnectHandlers;
public:

  bool Connect(int playerid);
  bool OnConnect(std::function<bool(CPlayer*)> callback);

  bool Spawn(int playerid);
  bool OnSpawn(std::function<bool(CPlayer*)> callback);

  bool Disconnect(int playerid, int reason);
  bool OnDisconnect(std::function<bool(CPlayer*, int)> callback);


  CPlayer* operator[](int playerid) {
    return this->playersPool[playerid];
  }

  bool IsConnected(int playerid) {
    return this->playersPool[playerid] != nullptr;
  }

  int GetMaxID() {
    return this->maxID;
  }
};

