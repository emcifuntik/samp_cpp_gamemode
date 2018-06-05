#include "stdafx.h"

CObject * CObjectFactory::Create(int modelid, double x, double y, double z, double rx, double ry, double rz, int worldid, int interiorid, int playerid, float streamdistance, float drawdistance, int areaid, int priority)
{
	CObject* obj = new CObject(modelid, x, y, z, rx, ry, rz, worldid, interiorid, playerid, streamdistance, drawdistance, areaid, priority);
	pool.push_back(obj);
	return obj;
}

bool CObjectFactory::Destroy(CObject * object)
{
	if (object) {
		delete[] object;
		return true;
	}
	return false;
}

void CObjectFactory::DestroyAll()
{
	for (CObject* obj : pool) {
		delete[] obj;
	}
	pool.clear();
}
