#include "stdafx.h"

CActor * CActorFactory::Create(int modelid, float x, float y, float z, float r, bool invulnerable, float health, int worldid, int interiorid, int playerid, float streamdistance, int areaid, int priority)
{
	CActor* actor = new CActor(modelid, x, y, z, r, invulnerable, health, worldid, interiorid, playerid, streamdistance, areaid, priority);
	pool.push_back(actor);
	idToActor.insert(std::pair<int, CActor*>(actor->GetID(), actor));
	return actor;
}

bool CActorFactory::Destroy(CActor * actor)
{
	if (actor) {
		pool.erase(std::find(pool.begin(), pool.end(), actor));
		idToActor.erase(actor->GetID());
		delete[] actor;
		return true;
	}
	return false;
}

void CActorFactory::DestroyAll()
{
	for (CActor* actor : pool) {
		delete[] actor;
	}
	idToActor.clear();
	pool.clear();
}

CActor * CActorFactory::GetByID(int id)
{
	if (idToActor.find(id) != idToActor.end())
		return idToActor.at(id);
	return nullptr;
}
