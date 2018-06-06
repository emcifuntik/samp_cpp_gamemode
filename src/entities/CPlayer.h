#pragma once
#define DIALOG_ID_DEFAULT 0
#undef SendMessage

class CVehicle;

struct Position {
	float x;
	float y;
	float z;
};

class CPlayer
{
	unsigned short playerid;
public:
	std::variant<std::function<bool(bool)>, std::function<bool(int)>, std::function<bool(const char*)>, bool> dialogCallback;
	bool loggedIn = false;
	Position lastPosition = { 0, 0, 0 };
	float heading = 0.f;
	int sqlID = 0;

	CPlayer(unsigned short playerid);
	~CPlayer();
	
	bool ShowChoiceDialog(const char * caption, const char * info, const char * button1, const char * button2, std::function<bool(bool)> callback = nullptr);
	bool ShowChoiceDialog(const char * caption, const char * info, const char * button1, std::function<bool(bool)> callback = nullptr) { return ShowChoiceDialog(caption, info, button1, "", callback); }
	bool ShowListboxDialog(const char * caption, const char * info, const char * button1, const char * button2, std::function<bool(int)> callback = nullptr);
	bool ShowListboxDialog(const char * caption, const char * info, const char * button1, std::function<bool(int)> callback = nullptr) { return ShowListboxDialog(caption, info, button1, "", callback); }
	bool ShowTablistDialog(const char * caption, const char * info, const char * button1, const char * button2, std::function<bool(int)> callback = nullptr);
	bool ShowTablistDialog(const char * caption, const char * info, const char * button1, std::function<bool(int)> callback = nullptr) { return ShowTablistDialog(caption, info, button1, "", callback); }
	bool ShowTablistHeadersDialog(const char * caption, const char * info, const char * button1, const char * button2, std::function<bool(int)> callback = nullptr);
	bool ShowTablistHeadersDialog(const char * caption, const char * info, const char * button1, std::function<bool(int)> callback = nullptr) { return ShowTablistHeadersDialog(caption, info, button1, "", callback); }
	bool ShowInputtextDialog(const char * caption, const char * info, const char * button1, const char * button2, std::function<bool(const char*)> callback = nullptr);
	bool ShowInputtextDialog(const char * caption, const char * info, const char * button1, std::function<bool(const char*)> callback = nullptr) { return ShowInputtextDialog(caption, info, button1, "", callback); }
	bool ShowPasswordDialog(const char * caption, const char * info, const char * button1, const char * button2, std::function<bool(const char*)> callback = nullptr);
	bool ShowPasswordDialog(const char * caption, const char * info, const char * button1, std::function<bool(const char*)> callback = nullptr) { return ShowPasswordDialog(caption, info, button1, "", callback); }
	bool HideDialog();
	bool SendMessage(int color, const char * message);
	bool SetSpawnInfo(int team, int skin, float x, float y, float z, float rotation, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo);
	bool Spawn();
	bool SetPos(float x, float y, float z);
	bool SetPosFindZ(float x, float y, float z);
	bool GetPos(float &x, float &y, float &z);
	bool SetFacingAngle(float angle);
	bool GetFacingAngle(float &angle);
	bool IsInRangeOfPoint(float range, float x, float y, float z);
	float GetDistanceFromPoint(float x, float y, float z);
	bool IsStreamedIn(int forplayerid);
	bool SetInterior(int interiorid);
	int GetInterior();
	bool SetHealth(float health);
	bool GetHealth(float * health);
	bool SetArmour(float armour);
	bool GetArmour(float * armour);
	bool SetAmmo(int weaponid, int ammo);
	int GetAmmo();
	int GetWeaponState();
	int GetTarget();
	int GetTargetActor();
	bool SetTeam(int teamid);
	int GetTeam();
	bool SetScore(int score);
	int GetScore();
	int GetDrunkLevel();
	bool SetDrunkLevel(int level);
	bool SetColor(int color);
	int GetColor();
	bool SetSkin(int skinid);
	int GetSkin();
	bool GiveWeapon(int weaponid, int ammo);
	bool ResetWeapons();
	bool SetArmedWeapon(int weaponid);
	bool GetWeaponData(int slot, int * weapon, int * ammo);
	bool GiveMoney(int money);
	bool ResetMoney();
	int SetName(const char * name);
	int GetMoney();
	int GetState();
	bool GetIp(char * ip, int size);
	int GetID();
	int GetPing();
	int GetWeapon();
	bool GetKeys(int * keys, int * updown, int * leftright);
	int GetName(char * name, int size);
	bool SetTime(int hour, int minute);
	bool GetTime(int * hour, int * minute);
	bool ToggleClock(bool toggle);
	bool SetWeather(int weather);
	bool ForceClassSelection();
	bool SetWantedLevel(int level);
	int GetWantedLevel();
	bool SetFightingStyle(int style);
	int GetFightingStyle();
	bool SetVelocity(float x, float y, float z);
	bool GetVelocity(float * x, float * y, float * z);
	bool PlayCrimeReport(int suspectid, int crime);
	bool PlayAudioStream(const char * url, float posX, float posY, float posZ, float distance, bool usepos);
	bool StopAudioStream();
	bool SetShopName(const char * shopname);
	bool SetSkillLevel(int skill, int level);
	int GetSurfingVehicleID();
	int GetSurfingObjectID();
	bool RemoveBuilding(int modelid, float fX, float fY, float fZ, float fRadius);
	bool GetLastShotVectors(float * fOriginX, float * fOriginY, float * fOriginZ, float * fHitPosX, float * fHitPosY, float * fHitPosZ);
	bool SetAttachedObject(int index, int modelid, int bone, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ, float fScaleX, float fScaleY, float fScaleZ, int materialcolor1, int materialcolor2);
	bool RemoveAttachedObject(int index);
	bool IsAttachedObjectSlotUsed(int index);
	bool EditAttachedObject(int index);
	int CreateTextDraw(float x, float y, const char * text);
	bool TextDrawDestroy(int text);
	bool TextDrawLetterSize(int text, float x, float y);
	bool TextDrawTextSize(int text, float x, float y);
	bool TextDrawAlignment(int text, int alignment);
	bool TextDrawColor(int text, int color);
	bool TextDrawUseBox(int text, bool use);
	bool TextDrawBoxColor(int text, int color);
	bool TextDrawSetShadow(int text, int size);
	bool TextDrawSetOutline(int text, int size);
	bool TextDrawBackgroundColor(int text, int color);
	bool TextDrawFont(int text, int font);
	bool TextDrawSetProportional(int text, bool set);
	bool TextDrawSetSelectable(int text, bool set);
	bool TextDrawShow(int text);
	bool TextDrawHide(int text);
	bool TextDrawSetString(int text, const char * string);
	bool TextDrawSetPreviewModel(int text, int modelindex);
	bool TextDrawSetPreviewRot(int text, float fRotX, float fRotY, float fRotZ, float fZoom);
	bool TextDrawSetPreviewVehCol(int text, int color1, int color2);
	bool SetPVarInt(const char * varname, int value);
	int GetPVarInt(const char * varname);
	bool SetPVarString(const char * varname, const char * value);
	bool GetPVarString(const char * varname, char * value, int size);
	bool SetPVarFloat(const char * varname, float value);
	float GetPVarFloat(const char * varname);
	bool DeletePVar(const char * varname);
	int GetPVarsUpperIndex();
	bool GetPVarNameAtIndex(int index, char * varname, int size);
	int GetPVarType(const char * varname);
	bool SetChatBubble(const char * text, int color, float drawdistance, int expiretime);
	bool PutInVehicle(CVehicle* vehicle, int seatid);
	int GetVehicleID();
	int GetVehicleSeat();
	bool RemoveFromVehicle();
	bool ToggleControllable(bool toggle);
	bool PlaySound(int soundid, float x, float y, float z);
	bool ApplyAnimation(const char * animlib, const char * animname, float fDelta, bool loop, bool lockx, bool locky, bool freeze, int time, bool forcesync);
	bool ClearAnimations(bool forcesync);
	int GetAnimationIndex();
	int GetSpecialAction();
	bool SetSpecialAction(int actionid);
	bool DisableRemoteVehicleCollisions(bool disable);
	bool SetCheckpoint(float x, float y, float z, float size);
	bool DisableCheckpoint();
	bool SetRaceCheckpoint(int type, float x, float y, float z, float nextx, float nexty, float nextz, float size);
	bool DisableRaceCheckpoint();
	bool SetWorldBounds(float x_max, float x_min, float y_max, float y_min);
	bool SetMarker(int showplayerid, int color);
	bool ShowNameTag(int showplayerid, bool show);
	bool SetMapIcon(int iconid, float x, float y, float z, int markertype, int color, int style);
	bool RemoveMapIcon(int iconid);
	bool AllowTeleport(bool allow);
	bool SetCameraPos(float x, float y, float z);
	bool SetCameraLookAt(float x, float y, float z, int cut);
	bool SetCameraBehindPlayer();
	bool GetCameraPos(float * x, float * y, float * z);
	bool GetCameraFrontVector(float * x, float * y, float * z);
	int GetCameraMode();
	bool EnableCameraTarget(bool enable);
	int GetCameraTargetObject();
	int GetCameraTargetVehicle();
	int GetCameraTarget();
	int GetCameraTargetActor();
	float GetCameraAspectRatio();
	float GetCameraZoom();
	bool AttachCameraToObject(int objectid);
	bool AttachCameraToPlayerObject(int playerobjectid);
	bool InterpolateCameraPos(float FromX, float FromY, float FromZ, float ToX, float ToY, float ToZ, int time, int cut);
	bool InterpolateCameraLookAt(float FromX, float FromY, float FromZ, float ToX, float ToY, float ToZ, int time, int cut);
	bool IsConnected();
	bool IsInVehicle(int vehicleid);
	bool IsInAnyVehicle();
	bool IsInCheckpoint();
	bool IsInRaceCheckpoint();
	bool SetVirtualWorld(int worldid);
	int GetVirtualWorld();
	bool EnableStuntBonus(bool enable);
	bool ToggleSpectating(bool toggle);
	bool Spectate(int targetplayerid, int mode);
	bool SpectateVehicle(int targetvehicleid, int mode);
	bool StartRecordingData(int recordtype, const char * recordname);
	bool StopRecordingData();
	bool CreateExplosion(float X, float Y, float Z, int type, float Radius);
};

