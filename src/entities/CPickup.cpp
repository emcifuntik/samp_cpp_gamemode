#include "stdafx.h"

CPickup::CPickup(int modelid, int type, float x, float y, float z, int worldid, int interiorid, int playerid, float streamdistance, int areaid, int priority)
{
	handler = Plugins::Streamer::Pickup::Create(modelid, type, x, y, z, worldid, interiorid, playerid, streamdistance, areaid, priority);
	area = Plugins::Streamer::Area::CreateSphere(x, y, z, 1.f, worldid, interiorid, playerid, priority);
}

CPickup::~CPickup()
{
	Plugins::Streamer::Pickup::Destroy(handler);
}

int CPickup::GetID()
{
	return handler;
}

int CPickup::GetAreaID()
{
	return area;
}

bool CPickup::IsValid()
{
	return Plugins::Streamer::Pickup::IsValid(handler);
}

void CPickup::OnPickedUp(std::function<void(CPlayer*)> callback)
{
	pickedUp = callback;
}

void CPickup::Picked(CPlayer * player)
{
	if (pickedUp) {
		pickedUp(player);
	}
}
