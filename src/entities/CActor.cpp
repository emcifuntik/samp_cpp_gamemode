#include "stdafx.h"

CActor::CActor(int modelid, float x, float y, float z, float r, bool invulnerable, float health, int worldid, int interiorid, int playerid, float streamdistance, int areaid, int priority)
{
	handler = Plugins::Streamer::Actor::Create(modelid, x, y, z, r, invulnerable, health, worldid, interiorid, playerid, streamdistance, areaid, priority);
}

CActor::~CActor()
{
	Plugins::Streamer::Actor::Destroy(handler);
}

int CActor::GetID()
{
	return handler;
}

bool CActor::IsValid()
{
	return handler;
}

void CActor::OnDamaged(std::function<void(CPlayer*, float, int, int)> callback)
{
	damaged = callback;
}

void CActor::Damaged(CPlayer * player, float amount, int weaponid, int bodypart)
{
	if (damaged)
		damaged(player, amount, weaponid, bodypart);
}

bool CActor::IsStreamedIn(CPlayer * player)
{
	return 	Plugins::Streamer::Actor::IsStreamedIn(handler, player->GetID());
}

int CActor::GetVirtualWorld()
{
	return 	Plugins::Streamer::Actor::GetVirtualWorld(handler);
}

bool CActor::SetVirtualWorld(int vworld)
{
	return Plugins::Streamer::Actor::SetVirtualWorld(handler, vworld);
}

bool CActor::ApplyAnimation(const char animlib[], const char animname[], float fdelta, bool loop, int lockx, int locky, int freeze, int time)
{
	return Plugins::Streamer::Actor::ApplyAnimation(handler, animlib, animname, fdelta, loop, lockx, locky, freeze, time);
}

bool CActor::ClearAnimations()
{
	return Plugins::Streamer::Actor::ClearAnimations(handler);
}

bool CActor::GetFacingAngle(float & ang)
{
	return Plugins::Streamer::Actor::GetFacingAngle(handler, &ang);
}

bool CActor::SetFacingAngle(float ang)
{
	return Plugins::Streamer::Actor::SetFacingAngle(handler, ang);
}

bool CActor::GetPos(float & x, float & y, float & z)
{
	return Plugins::Streamer::Actor::GetPos(handler, &x, &y, &z);
}

bool CActor::SetPos(float x, float y, float z)
{
	return Plugins::Streamer::Actor::SetPos(handler, x, y, z);
}

bool CActor::GetHealth(float & health)
{
	return Plugins::Streamer::Actor::GetHealth(handler, &health);
}

bool CActor::SetHealth(float health)
{
	return Plugins::Streamer::Actor::SetHealth(handler, health);
}

bool CActor::SetInvulnerable(bool invulnerable)
{
	return Plugins::Streamer::Actor::SetInvulnerable(handler, invulnerable);
}

bool CActor::IsInvulnerable()
{
	return Plugins::Streamer::Actor::IsInvulnerable(handler);
}

int CActor::GetPlayerTarget(CPlayer * player)
{
	return Plugins::Streamer::Actor::GetPlayerTarget(player->GetID());
}

int CActor::GetPlayerCameraTarget(CPlayer * player)
{
	return Plugins::Streamer::Actor::GetPlayerCameraTarget(player->GetID());
}
