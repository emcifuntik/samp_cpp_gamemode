#include "stdafx.h"

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerRequestClass(int playerid, int classid) {
  sampgdk::SpawnPlayer(playerid);
  return true;
}
