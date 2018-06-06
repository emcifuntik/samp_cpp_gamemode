#pragma once

class CActorFactory : public CSingleton<CActorFactory> {
	std::list<CActor*> pool;
	std::unordered_map<int, CActor*> idToActor;
public:
	CActor * Create(int modelid, float x, float y, float z, float r, bool invulnerable = 1, float health = 100.0, int worldid = -1, int interiorid = -1, int playerid = -1, float streamdistance = STREAMER_ACTOR_SD, int areaid = -1, int priority = 0);
	bool Destroy(CActor* actor);
	void DestroyAll();
	CActor * GetByID(int id);
};