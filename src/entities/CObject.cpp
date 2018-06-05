#include "stdafx.h"

CObject::CObject(int modelid, double x, double y, double z, double rx, double ry, double rz, int worldid, int interiorid, int playerid, float streamdistance, float drawdistance, int areaid, int priority) {
	handler = Plugins::Streamer::Object::Create(modelid, x, y, z, rx, ry, rz, worldid, interiorid, playerid, streamdistance, drawdistance, areaid, priority);
}


CObject::~CObject() {
	Plugins::Streamer::Object::Destroy(handler);
}

int CObject::GetID()
{
	return handler;
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

bool CObject::SetRotation(float rx, float ry, float rz)
{
	return Plugins::Streamer::Object::SetRot(handler, rx, ry, rz);
}

bool CObject::GetRotation(float * rx, float * ry, float * rz)
{
	return Plugins::Streamer::Object::GetRot(handler, rx,ry ,rz);
}

bool CObject::SetNoCameraCol()
{
	return Plugins::Streamer::Object::SetNoCameraCol(handler);
}

bool CObject::GetNoCameraCol()
{
	return Plugins::Streamer::Object::GetNoCameraCol(handler);
}

bool CObject::Move(float x, float y, float z, float speed, float rx, float ry, float rz)
{
	return Plugins::Streamer::Object::Move(handler, x, y, z, speed, rx, ry, rz);
}

bool CObject::StopMoving()
{
	return Plugins::Streamer::Object::Stop(handler);
}

bool CObject::IsMoving()
{
	return Plugins::Streamer::Object::IsMoving(handler);
}

bool CObject::AttachPlayerCamera(CPlayer *player)
{
	return Plugins::Streamer::Object::AttachCameraTo(player->GetID(), handler);
}

bool CObject::AttachToObject(CObject * object, float offsetx, float offsety, float offsetz, float rx, float ry, float rz, int syncrotation)
{
	return Plugins::Streamer::Object::AttachToObject(handler, object->GetID(), offsetx, offsety, offsetz, rx, ry, rz, syncrotation);
}

bool CObject::AttachToPlayer(CPlayer * player, float offsetx, float offsety, float offsetz, float rx, float ry, float rz)
{
	return Plugins::Streamer::Object::AttachToPlayer(handler, player->GetID(), offsetx, offsety, offsetz, rx, ry, rz);
}

bool CObject::AttachToVehicle(CVehicle* vehicle, float offsetx, float offsety, float offsetz, float rx, float ry, float rz)
{
	return Plugins::Streamer::Object::AttachToVehicle(handler, vehicle->GetID(), offsetx, offsety, offsetz, rx, ry, rz);
}

bool CObject::Edit(CPlayer * player)
{
	return Plugins::Streamer::Object::Edit(player->GetID(), handler);
}

bool CObject::IsMaterialUsed(int materialindex)
{
	return Plugins::Streamer::Object::IsMaterialUsed(handler, materialindex);
}

bool CObject::GetMaterial(int materialindex, int * modelid, char txdname[], char texturename[], int * materialcolor, int maxtxdname, int maxtexturename)
{
	return Plugins::Streamer::Object::GetMaterial(handler, materialindex, modelid, txdname, texturename, materialcolor, maxtxdname, maxtexturename);
}

bool CObject::SetMaterial(int materialindex, int modelid, const char txdname[], const char texturename[], int materialcolor)
{
	return Plugins::Streamer::Object::SetMaterial(handler, materialindex, modelid, txdname, texturename, materialcolor);
}

bool CObject::IsMaterialTextUsed(int materialindex)
{
	return Plugins::Streamer::Object::IsMaterialTextUsed(handler, materialindex);
}

bool CObject::GetMaterialText(int materialindex, char text[], int * materialsize, char fontface[], int * fontsize, int * bold, int * fontcolor, int * backcolor, int * textalignment, int maxtext, int maxfontface)
{
	return Plugins::Streamer::Object::GetMaterialText(handler, materialindex, text, materialsize, fontface, fontsize, bold, fontcolor, backcolor, textalignment, maxtext, maxfontface);
}

bool CObject::SetMaterialText(int materialindex, const char text[], int materialsize, const char fontface[], int fontsize, int bold, int fontcolor, int backcolor, int textalignment)
{
	return Plugins::Streamer::Object::SetMaterialText(handler, materialindex, text, materialsize, fontface, fontsize, bold, fontcolor, backcolor, textalignment);
}

