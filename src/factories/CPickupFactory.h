#pragma once

class CPickupFactory : public CSingleton<CPickupFactory> {
	std::list<CPickup*> pool;
	std::unordered_map<int, CPickup*> idToPickup;
public:
	CPickup * Create(int modelid, int type, float x, float y, float z, int worldid = -1, int interiorid = -1, int playerid = -1, float streamdistance = STREAMER_PICKUP_SD, int areaid = -1, int priority = 0);
	bool Destroy(CPickup* pickup);
	void DestroyAll();
	CPickup* GetByAreaID(int id);
};