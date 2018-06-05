#include "stdafx.h"

CObject::CObject(int modelid, double x, double y, double z, double rx, double ry, double rz, int worldid, int interiorid, int playerid, float streamdistance, float drawdistance, int areaid, int priority) {
	handler = Plugins::Streamer::Object::Create(modelid, x, y, z, rx, ry, rz, worldid, interiorid, playerid, streamdistance, drawdistance, areaid, priority);
}


CObject::~CObject() {
	Plugins::Streamer::Object::Destroy(handler);
}

bool CObject::IsValid()
{
	return Plugins::Streamer::Object::IsValid(handler);
}

bool CObject::SetPosition(float x, float y, float z)
{
	return Plugins::Streamer::Object::SetPos(handler, x, y, z);
}

bool CObject::GetPosition(float * x, float * y, float * z)
{
	return Plugins::Streamer::Object::GetPos(handler, x, y, z);
}

