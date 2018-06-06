#include "stdafx.h"

CVehicle * CVehicleFactory::Create(int model, float x, float y, float z, float a, int color1, int color2, int respawnDelay, bool addSiren)
{
	CVehicle* veh = new CVehicle(model, x, y, z, a, color1, color2, respawnDelay, addSiren);
	pool.push_back(veh);
	return veh;
}

bool CVehicleFactory::Destroy(CVehicle * vehicle)
{
	if (vehicle) {
		delete vehicle;
		return true;
	}
	return false;
}

void CVehicleFactory::DestroyAll()
{
	for (CVehicle* veh : pool) {
		delete veh;
	}
	pool.clear();
}
