#pragma once
class CVehicle
{
	int id;
public:
	CVehicle(int model, float x, float y, float z, float a, int color1, int color2, int respawnDelay = 0, bool addSiren = false);
	~CVehicle();
	bool IsValid();
	float GetDistanceFromPoint(float x, float y, float z);
	bool IsStreamedIn(int forplayerid);
	bool GetPos(float * x, float * y, float * z);
	bool SetPos(float x, float y, float z);
	bool GetZAngle(float * z_angle);
	bool GetRotationQuat(float * w, float * x, float * y, float * z);
	bool SetZAngle(float z_angle);
	bool SetParamsForPlayer(int playerid, int objective, int doorslocked);
	bool ManualEngineAndLights();
	bool SetParamsEx(int engine, int lights, int alarm, int doors, int bonnet, int boot, int objective);
	bool GetParamsEx(int * engine, int * lights, int * alarm, int * doors, int * bonnet, int * boot, int * objective);
	int GetParamsSirenState();
	bool SetParamsCarDoors(int driver, int passenger, int backleft, int backright);
	bool GetParamsCarDoors(int * driver, int * passenger, int * backleft, int * backright);
	bool SetParamsCarWindows(int driver, int passenger, int backleft, int backright);
	bool GetParamsCarWindows(int * driver, int * passenger, int * backleft, int * backright);
	bool SetToRespawn();
	bool LinkToInterior(int interiorid);
	bool AddComponent(int componentid);
	bool RemoveComponent(int componentid);
	bool ChangeColor(int color1, int color2);
	bool ChangePaintjob(int paintjobid);
	bool SetHealth(float health);
	bool GetHealth(float * health);
	bool AttachTrailer(int trailerid);
	bool DetachTrailer();
	bool IsTrailerAttached();
	int GetTrailer();
	bool SetNumberPlate(const char * numberplate);
	int GetModel();
	int GetComponentInSlot(int slot);
	int GetComponentType(int component);
	bool Repair();
	bool GetVelocity(float * X, float * Y, float * Z);
	bool SetVelocity(float X, float Y, float Z);
	bool SetAngularVelocity(float X, float Y, float Z);
	bool GetDamageStatus(int * panels, int * doors, int * lights, int * tires);
	bool UpdateDamageStatus(int panels, int doors, int lights, int tires);
	bool SetVirtualWorld(int worldid);
	int GetVirtualWorld();
	bool GetModelInfo(int model, int infotype, float * X, float * Y, float * Z);
};

