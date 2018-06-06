#include "stdafx.h"

CPickup * CPickupFactory::Create(int modelid, int type, float x, float y, float z, int worldid, int interiorid, int playerid, float streamdistance, int areaid, int priority)
{
	CPickup* pickup = new CPickup(modelid, type, x, y, z, worldid, interiorid, playerid, streamdistance, areaid, priority);
	pool.push_back(pickup);
	idToPickup.insert(std::pair<int, CPickup*>(pickup->GetAreaID(), pickup));
	return pickup;
}

bool CPickupFactory::Destroy(CPickup * pickup)
{
	if (pickup) {
		pool.erase(std::find(pool.begin(), pool.end(), pickup));
		idToPickup.erase(pickup->GetID());
		delete[] pickup;
		return true;
	}
	return false;
}

void CPickupFactory::DestroyAll()
{
	for (CPickup* pickup : pool) {
		delete[] pickup;
	}
	idToPickup.clear();
	pool.clear();
}

CPickup * CPickupFactory::GetByAreaID(int id)
{
	if (idToPickup.find(id) != idToPickup.end())
		return idToPickup.at(id);
	return nullptr;
}
