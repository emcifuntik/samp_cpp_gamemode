#pragma once

class CPickup {
	friend class CPickupFactory;
	int handler = -1;
	int area = -1;
	std::function<void(CPlayer*)> pickedUp;

	CPickup(int modelid, int type, float x, float y, float z, int worldid = -1, int interiorid = -1, int playerid = -1, float streamdistance = STREAMER_PICKUP_SD, int areaid = -1, int priority = 0);
	~CPickup();
public:
	int GetID();
	int GetAreaID();
	bool IsValid();
	void OnPickedUp(std::function<void(CPlayer*)> callback);
	void Picked(CPlayer* player);
};