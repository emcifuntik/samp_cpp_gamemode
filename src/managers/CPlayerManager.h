#pragma once

class CPlayerManager
{
  CPlayerManager();
  ~CPlayerManager();
  CPlayer * playersPool[1000] = { nullptr };
  int maxID = 0;

  std::vector<std::function<bool(CPlayer*)>> connectHandlers;
  std::vector<std::function<bool(CPlayer*)>> spawnHandlers;
  std::vector<std::function<bool(CPlayer*, int)>> disconnectHandlers;
public:
  static CPlayerManager & Get() {
    static CPlayerManager instance;
    return instance;
  }

  bool Connect(int playerid);
  bool Spawn(int playerid);
  bool Disconnect(int playerid, int reason);

  bool OnConnect(std::function<bool(CPlayer*)> callback);
  bool OnSpawn(std::function<bool(CPlayer*)> callback);
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

