#pragma once

//class CArea {
//	int handler = -1;
//	std::function<void(CPlayer*)> entered;
//
//	CArea(float x, float y, float size, int worldid = -1, int interiorid = -1, int playerid = -1, int priority = 0);
//	CArea(float x, float y, float minz, float maxz, float size, int worldid = -1, int interiorid = -1, int playerid = -1, int priority = 0);
//	CArea(float x, float y, float z, float size, int worldid = -1, int interiorid = -1, int playerid = -1, int priority = 0);
//	~CArea();
//public:
//	int GetID();
//	bool IsValid();
//	void OnEntered(std::function<void(CPlayer*)> callback);
//	void Entered(CPlayer* player);
//
//
//
//	int CreateCircle(float x, float y, float size, int worldid = -1, int interiorid = -1, int playerid = -1, int priority = 0);
//	int CreateCylinder(float x, float y, float minz, float maxz, float size, int worldid = -1, int interiorid = -1, int playerid = -1, int priority = 0);
//	int CreateSphere(float x, float y, float z, float size, int worldid = -1, int interiorid = -1, int playerid = -1, int priority = 0);
//	int CreateRectangle(float minx, float miny, float maxx, float maxy, int worldid = -1, int interiorid = -1, int playerid = -1, int priority = 0);
//	int CreateCuboid(float minx, float miny, float minz, float maxx, float maxy, float maxz, int worldid = -1, int interiorid = -1, int playerid = -1, int priority = 0);
//	int CreateCube(float minx, float miny, float minz, float maxx, float maxy, float maxz, int worldid = -1, int interiorid = -1, int playerid = -1, int priority = 0);
//	int CreatePolygon(const float points[], float minz, float maxz, int maxpoints, int worldid = -1, int interiorid = -1, int playerid = -1, int priority = 0);
//	bool Destroy(int areaid);
//	bool IsValid(int areaid);
//	int GetType(int areaid);
//	int GetDynamicPolygonPoints(int areaid, float points[], int maxpoints);
//	int GetDynamicPolygonNumberPoints(int areaid);
//	bool IsPlayerIn(int playerid, int areaid, bool recheck = 0);
//	bool IsPlayerInAny(int playerid, bool recheck = 0);
//	bool IsAnyPlayerIn(int areaid, bool recheck = 0);
//	bool IsAnyPlayerInAny(bool recheck = 0);
//	int GetPlayerDynamicAreas(int playerid, int areas[], int maxareas);
//	int GetPlayerNumber(int playerid);
//	bool IsPointIn(int areaid, float x, float y, float z);
//	bool IsPointInAny(float x, float y, float z);
//	bool IsLineIn(int areaid, float x1, float y1, float z1, float x2, float y2, float z2);
//	bool IsLineInAny(float x1, float y1, float z1, float x2, float y2, float z2);
//	int GetDynamicAreasForPoint(float x, float y, float z, int areas[], int maxareas);
//	int GetNumberDynamicAreasForPoint(float x, float y, float z);
//	int GetDynamicAreasForLine(float x1, float y1, float z1, float x2, float y2, float z2, int areas[], int maxareas);
//	int GetNumberForLine(float x1, float y1, float z1, float x2, float y2, float z2);
//	bool AttachToObject(int areaid, int objectid, int type = STREAMER_OBJECT_TYPE_DYNAMIC, int playerid = INVALID_PLAYER_ID, float offsetx = 0.0, float offsety = 0.0, float offsetz = 0.0);
//	bool AttachToPlayer(int areaid, int playerid, float offsetx = 0.0, float offsety = 0.0, float offsetz = 0.0);
//	bool AttachToVehicle(int areaid, int vehicleid, float offsetx = 0.0, float offsety = 0.0, float offsetz = 0.0);
//	bool ToggleSpectateMode(int areaid, bool toggle);
//	bool IsToggleSpectateMode(int areaid);
//};