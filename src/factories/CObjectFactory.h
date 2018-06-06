#pragma once

class CObjectFactory : public CSingleton<CObjectFactory> {
	std::list<CObject*> pool;
public:
	CObject * Create(int modelid, double x, double y, double z, double rx, double ry, double rz, int worldid = -1, int interiorid = -1, int playerid = -1, float streamdistance = STREAMER_OBJECT_SD, float drawdistance = STREAMER_OBJECT_DD, int areaid = -1, int priority = 0);
	bool Destroy(CObject* object);
	void DestroyAll();
};