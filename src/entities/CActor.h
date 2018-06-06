#pragma once

class CActor {
	friend class CActorFactory;
	int handler = -1;
	std::function<void(CPlayer*, float, int, int)> damaged;

	CActor(int modelid, float x, float y, float z, float r, bool invulnerable = 1, float health = 100.0, int worldid = -1, int interiorid = -1, int playerid = -1, float streamdistance = STREAMER_ACTOR_SD, int areaid = -1, int priority = 0);
	~CActor();
public:
	int GetID();
	bool IsValid();
	void OnDamaged(std::function<void(CPlayer*, float, int, int)> callback);
	void Damaged(CPlayer* player, float amount, int weaponid, int bodypart);

	bool IsStreamedIn(CPlayer* player);
	int GetVirtualWorld();
	bool SetVirtualWorld(int vworld);
	bool ApplyAnimation(const char animlib[], const char animname[], float fdelta, bool loop, int lockx, int locky, int freeze, int time);
	bool ClearAnimations();
	bool GetFacingAngle(float &ang);
	bool SetFacingAngle(float ang);
	bool GetPos(float &x, float &y, float &z);
	bool SetPos(float x, float y, float z);
	bool GetHealth(float &health);
	bool SetHealth(float health);
	bool SetInvulnerable(bool invulnerable = true);
	bool IsInvulnerable();

	//TODO: Rework
	int GetPlayerTarget(CPlayer* player);
	int GetPlayerCameraTarget(CPlayer* player);
};