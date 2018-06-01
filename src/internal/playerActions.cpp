#include "stdafx.h"

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerRequestClass(int playerid, int classid) {
  sampgdk::SpawnPlayer(playerid);
  return true;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerSpawn(int playerid) {
  return CPlayerManager::Get().Spawn(playerid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerDisconnect(int playerid, int reason) {
	return CPlayerManager::Get().Disconnect(playerid, reason);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerConnect(int playerid) {
	CPlayer * player = CPlayerManager::Get()[playerid];
	CPlayerManager::Get().Connect(playerid);
	return true;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnDialogResponse(int playerid, int dialogid, int response, int listitem, const char * inputtext)
{
	CPlayer * player = CPlayerManager::Get()[playerid];
	if (player) {
		switch (player->dialog.currentDialogStyle) {
		case DialogStyle::Choice:
			player->dialog.choiceCallback(response == 1);
			break;
		case DialogStyle::Input:
			player->dialog.inputCallback(inputtext);
			break;
		case DialogStyle::List:
			player->dialog.choiceCallback(listitem);
			break;
		}
	}
	return true;
}
