#include "stdafx.h"


CPlayer::CPlayer(unsigned short playerid):playerid(playerid)
{
}

CPlayer::~CPlayer()
{
}

bool CPlayer::ShowChoiceDialog(const char * caption, const char * info, const char * button1, const char * button2, std::function<bool(bool)> callback)
{
	if (callback)
		this->dialogCallback = callback;
	else
		this->dialogCallback.operator=<bool>(false);
	return sampgdk::ShowPlayerDialog(this->playerid, DIALOG_ID_DEFAULT, DIALOG_STYLE_MSGBOX, caption, info, button1, button2);
}

bool CPlayer::ShowListboxDialog(const char * caption, const char * info, const char * button1, const char * button2, std::function<bool(int)> callback)
{
	if (callback)
		this->dialogCallback = callback;
	else
		this->dialogCallback.operator=<bool>(false);
	return sampgdk::ShowPlayerDialog(this->playerid, DIALOG_ID_DEFAULT, DIALOG_STYLE_LIST, caption, info, button1, button2);
}

bool CPlayer::ShowTablistDialog(const char * caption, const char * info, const char * button1, const char * button2, std::function<bool(int)> callback)
{
	if (callback)
		this->dialogCallback = callback;
	else
		this->dialogCallback.operator=<bool>(false);
	return sampgdk::ShowPlayerDialog(this->playerid, DIALOG_ID_DEFAULT, DIALOG_STYLE_TABLIST, caption, info, button1, button2);
}

bool CPlayer::ShowTablistHeadersDialog(const char * caption, const char * info, const char * button1, const char * button2, std::function<bool(int)> callback)
{
	if (callback)
		this->dialogCallback = callback;
	else
		this->dialogCallback.operator=<bool>(false);
	return sampgdk::ShowPlayerDialog(this->playerid, DIALOG_ID_DEFAULT, DIALOG_STYLE_TABLIST_HEADERS, caption, info, button1, button2);
}

bool CPlayer::ShowInputtextDialog(const char * caption, const char * info, const char * button1, const char * button2, std::function<bool(const char*)> callback)
{
	if (callback)
		this->dialogCallback = callback;
	else
		this->dialogCallback.operator=<bool>(false);
	return sampgdk::ShowPlayerDialog(this->playerid, DIALOG_ID_DEFAULT, DIALOG_STYLE_INPUT, caption, info, button1, button2);
}

bool CPlayer::ShowPasswordDialog(const char * caption, const char * info, const char * button1, const char * button2, std::function<bool(const char*)> callback)
{
	if (callback)
		this->dialogCallback = callback;
	else
		this->dialogCallback.operator=<bool>(false);
	return sampgdk::ShowPlayerDialog(this->playerid, DIALOG_ID_DEFAULT, DIALOG_STYLE_PASSWORD, caption, info, button1, button2);
}

bool CPlayer::HideDialog()
{
	this->dialogCallback.operator=<bool>(false);
	return sampgdk::ShowPlayerDialog(this->playerid, -1, 0, "", "", "", "");
}

bool CPlayer::SendMessage(int color, const char * message)
{
  return sampgdk::SendClientMessage(this->playerid, color, message);
}

bool CPlayer::SetSpawnInfo(int team, int skin, float x, float y, float z, float rotation, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo) {
  return sampgdk::SetSpawnInfo(this->playerid, team, skin, x, y, z, rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
}

bool CPlayer::Spawn() {
  return sampgdk::SpawnPlayer(this->playerid);
}

bool CPlayer::SetPos(float x, float y, float z) {
  return sampgdk::SetPlayerPos(this->playerid, x, y, z);
}

bool CPlayer::SetPosFindZ(float x, float y, float z) {
  return sampgdk::SetPlayerPosFindZ(this->playerid, x, y, z);
}

bool CPlayer::GetPos(float * x, float * y, float * z) {
  return sampgdk::GetPlayerPos(this->playerid, x, y, z);
}

bool CPlayer::SetFacingAngle(float angle) {
  return sampgdk::SetPlayerFacingAngle(this->playerid, angle);
}

bool CPlayer::GetFacingAngle(float * angle) {
  return sampgdk::GetPlayerFacingAngle(this->playerid, angle);
}

bool CPlayer::IsInRangeOfPoint(float range, float x, float y, float z) {
  return sampgdk::IsPlayerInRangeOfPoint(this->playerid, range, x, y, z);
}

float CPlayer::GetDistanceFromPoint(float x, float y, float z) {
  return sampgdk::GetPlayerDistanceFromPoint(this->playerid, x, y, z);
}

bool CPlayer::IsStreamedIn(int forplayerid) {
  return sampgdk::IsPlayerStreamedIn(this->playerid, forplayerid);
}

bool CPlayer::SetInterior(int interiorid) {
  return sampgdk::SetPlayerInterior(this->playerid, interiorid);
}

int CPlayer::GetInterior() {
  return sampgdk::GetPlayerInterior(this->playerid);
}

bool CPlayer::SetHealth(float health) {
  return sampgdk::SetPlayerHealth(this->playerid, health);
}

bool CPlayer::GetHealth(float * health) {
  return sampgdk::GetPlayerHealth(this->playerid, health);
}

bool CPlayer::SetArmour(float armour) {
  return sampgdk::SetPlayerArmour(this->playerid, armour);
}

bool CPlayer::GetArmour(float * armour) {
  return sampgdk::GetPlayerArmour(this->playerid, armour);
}

bool CPlayer::SetAmmo(int weaponid, int ammo) {
  return sampgdk::SetPlayerAmmo(this->playerid, weaponid, ammo);
}

int CPlayer::GetAmmo() {
  return sampgdk::GetPlayerAmmo(this->playerid);
}

int CPlayer::GetWeaponState() {
  return sampgdk::GetPlayerWeaponState(this->playerid);
}

int CPlayer::GetTarget() {
  return sampgdk::GetPlayerTargetPlayer(this->playerid);
}

int CPlayer::GetTargetActor() {
  return sampgdk::GetPlayerTargetActor(this->playerid);
}

bool CPlayer::SetTeam(int teamid) {
  return sampgdk::SetPlayerTeam(this->playerid, teamid);
}

int CPlayer::GetTeam() {
  return sampgdk::GetPlayerTeam(this->playerid);
}

bool CPlayer::SetScore(int score) {
  return sampgdk::SetPlayerScore(this->playerid, score);
}

int CPlayer::GetScore() {
  return sampgdk::GetPlayerScore(this->playerid);
}

int CPlayer::GetDrunkLevel() {
  return sampgdk::GetPlayerDrunkLevel(this->playerid);
}

bool CPlayer::SetDrunkLevel(int level) {
  return sampgdk::SetPlayerDrunkLevel(this->playerid, level);
}

bool CPlayer::SetColor(int color) {
  return sampgdk::SetPlayerColor(this->playerid, color);
}

int CPlayer::GetColor() {
  return sampgdk::GetPlayerColor(this->playerid);
}

bool CPlayer::SetSkin(int skinid) {
  return sampgdk::SetPlayerSkin(this->playerid, skinid);
}

int CPlayer::GetSkin() {
  return sampgdk::GetPlayerSkin(this->playerid);
}

bool CPlayer::GiveWeapon(int weaponid, int ammo) {
  return sampgdk::GivePlayerWeapon(this->playerid, weaponid, ammo);
}

bool CPlayer::ResetWeapons() {
  return sampgdk::ResetPlayerWeapons(this->playerid);
}

bool CPlayer::SetArmedWeapon(int weaponid) {
  return sampgdk::SetPlayerArmedWeapon(this->playerid, weaponid);
}

bool CPlayer::GetWeaponData(int slot, int * weapon, int * ammo) {
  return sampgdk::GetPlayerWeaponData(this->playerid, slot, weapon, ammo);
}

bool CPlayer::GiveMoney(int money) {
  return sampgdk::GivePlayerMoney(this->playerid, money);
}

bool CPlayer::ResetMoney() {
  return sampgdk::ResetPlayerMoney(this->playerid);
}

int CPlayer::SetName(const char * name) {
  return sampgdk::SetPlayerName(this->playerid, name);
}

int CPlayer::GetMoney() {
  return sampgdk::GetPlayerMoney(this->playerid);
}

int CPlayer::GetState() {
  return sampgdk::GetPlayerState(this->playerid);
}

bool CPlayer::GetIp(char * ip, int size) {
  return sampgdk::GetPlayerIp(this->playerid, ip, size);
}

int CPlayer::GetID()
{
	return playerid;
}

int CPlayer::GetPing() {
  return sampgdk::GetPlayerPing(this->playerid);
}

int CPlayer::GetWeapon() {
  return sampgdk::GetPlayerWeapon(this->playerid);
}

bool CPlayer::GetKeys(int * keys, int * updown, int * leftright) {
  return sampgdk::GetPlayerKeys(this->playerid, keys, updown, leftright);
}

int CPlayer::GetName(char * name, int size) {
  return sampgdk::GetPlayerName(this->playerid, name, size);
}

bool CPlayer::SetTime(int hour, int minute) {
  return sampgdk::SetPlayerTime(this->playerid, hour, minute);
}

bool CPlayer::GetTime(int * hour, int * minute) {
  return sampgdk::GetPlayerTime(this->playerid, hour, minute);
}

bool CPlayer::ToggleClock(bool toggle) {
  return sampgdk::TogglePlayerClock(this->playerid, toggle);
}

bool CPlayer::SetWeather(int weather) {
  return sampgdk::SetPlayerWeather(this->playerid, weather);
}

bool CPlayer::ForceClassSelection() {
  return sampgdk::ForceClassSelection(this->playerid);
}

bool CPlayer::SetWantedLevel(int level) {
  return sampgdk::SetPlayerWantedLevel(this->playerid, level);
}

int CPlayer::GetWantedLevel() {
  return sampgdk::GetPlayerWantedLevel(this->playerid);
}

bool CPlayer::SetFightingStyle(int style) {
  return sampgdk::SetPlayerFightingStyle(this->playerid, style);
}

int CPlayer::GetFightingStyle() {
  return sampgdk::GetPlayerFightingStyle(this->playerid);
}

bool CPlayer::SetVelocity(float x, float y, float z) {
  return sampgdk::SetPlayerVelocity(this->playerid, x, y, z);
}

bool CPlayer::GetVelocity(float * x, float * y, float * z) {
  return sampgdk::GetPlayerVelocity(this->playerid, x, y, z);
}

bool CPlayer::PlayCrimeReport(int suspectid, int crime) {
  return sampgdk::PlayCrimeReportForPlayer(this->playerid, suspectid, crime);
}

bool CPlayer::PlayAudioStream(const char * url, float posX, float posY, float posZ, float distance, bool usepos) {
  return sampgdk::PlayAudioStreamForPlayer(this->playerid, url, posX, posY, posZ, distance, usepos);
}

bool CPlayer::StopAudioStream() {
  return sampgdk::StopAudioStreamForPlayer(this->playerid);
}

bool CPlayer::SetShopName(const char * shopname) {
  return sampgdk::SetPlayerShopName(this->playerid, shopname);
}

bool CPlayer::SetSkillLevel(int skill, int level) {
  return sampgdk::SetPlayerSkillLevel(this->playerid, skill, level);
}

int CPlayer::GetSurfingVehicleID() {
  return sampgdk::GetPlayerSurfingVehicleID(this->playerid);
}

int CPlayer::GetSurfingObjectID() {
  return sampgdk::GetPlayerSurfingObjectID(this->playerid);
}

bool CPlayer::RemoveBuilding(int modelid, float fX, float fY, float fZ, float fRadius) {
  return sampgdk::RemoveBuildingForPlayer(this->playerid, modelid, fX, fY, fZ, fRadius);
}

bool CPlayer::GetLastShotVectors(float * fOriginX, float * fOriginY, float * fOriginZ, float * fHitPosX, float * fHitPosY, float * fHitPosZ) {
  return sampgdk::GetPlayerLastShotVectors(this->playerid, fOriginX, fOriginY, fOriginZ, fHitPosX, fHitPosY, fHitPosZ);
}

bool CPlayer::SetAttachedObject(int index, int modelid, int bone, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ, float fScaleX, float fScaleY, float fScaleZ, int materialcolor1, int materialcolor2) {
  return sampgdk::SetPlayerAttachedObject(this->playerid, index, modelid, bone, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, fScaleX, fScaleY, fScaleZ, materialcolor1, materialcolor2);
}

bool CPlayer::RemoveAttachedObject(int index) {
  return sampgdk::RemovePlayerAttachedObject(this->playerid, index);
}

bool CPlayer::IsAttachedObjectSlotUsed(int index) {
  return sampgdk::IsPlayerAttachedObjectSlotUsed(this->playerid, index);
}

bool CPlayer::EditAttachedObject(int index) {
  return sampgdk::EditAttachedObject(this->playerid, index);
}

int CPlayer::CreateTextDraw(float x, float y, const char * text) {
  return sampgdk::CreatePlayerTextDraw(this->playerid, x, y, text);
}

bool CPlayer::TextDrawDestroy(int text) {
  return sampgdk::PlayerTextDrawDestroy(this->playerid, text);
}

bool CPlayer::TextDrawLetterSize(int text, float x, float y) {
  return sampgdk::PlayerTextDrawLetterSize(this->playerid, text, x, y);
}

bool CPlayer::TextDrawTextSize(int text, float x, float y) {
  return sampgdk::PlayerTextDrawTextSize(this->playerid, text, x, y);
}

bool CPlayer::TextDrawAlignment(int text, int alignment) {
  return sampgdk::PlayerTextDrawAlignment(this->playerid, text, alignment);
}

bool CPlayer::TextDrawColor(int text, int color) {
  return sampgdk::PlayerTextDrawColor(this->playerid, text, color);
}

bool CPlayer::TextDrawUseBox(int text, bool use) {
  return sampgdk::PlayerTextDrawUseBox(this->playerid, text, use);
}

bool CPlayer::TextDrawBoxColor(int text, int color) {
  return sampgdk::PlayerTextDrawBoxColor(this->playerid, text, color);
}

bool CPlayer::TextDrawSetShadow(int text, int size) {
  return sampgdk::PlayerTextDrawSetShadow(this->playerid, text, size);
}

bool CPlayer::TextDrawSetOutline(int text, int size) {
  return sampgdk::PlayerTextDrawSetOutline(this->playerid, text, size);
}

bool CPlayer::TextDrawBackgroundColor(int text, int color) {
  return sampgdk::PlayerTextDrawBackgroundColor(this->playerid, text, color);
}

bool CPlayer::TextDrawFont(int text, int font) {
  return sampgdk::PlayerTextDrawFont(this->playerid, text, font);
}

bool CPlayer::TextDrawSetProportional(int text, bool set) {
  return sampgdk::PlayerTextDrawSetProportional(this->playerid, text, set);
}

bool CPlayer::TextDrawSetSelectable(int text, bool set) {
  return sampgdk::PlayerTextDrawSetSelectable(this->playerid, text, set);
}

bool CPlayer::TextDrawShow(int text) {
  return sampgdk::PlayerTextDrawShow(this->playerid, text);
}

bool CPlayer::TextDrawHide(int text) {
  return sampgdk::PlayerTextDrawHide(this->playerid, text);
}

bool CPlayer::TextDrawSetString(int text, const char * string) {
  return sampgdk::PlayerTextDrawSetString(this->playerid, text, string);
}

bool CPlayer::TextDrawSetPreviewModel(int text, int modelindex) {
  return sampgdk::PlayerTextDrawSetPreviewModel(this->playerid, text, modelindex);
}

bool CPlayer::TextDrawSetPreviewRot(int text, float fRotX, float fRotY, float fRotZ, float fZoom) {
  return sampgdk::PlayerTextDrawSetPreviewRot(this->playerid, text, fRotX, fRotY, fRotZ, fZoom);
}

bool CPlayer::TextDrawSetPreviewVehCol(int text, int color1, int color2) {
  return sampgdk::PlayerTextDrawSetPreviewVehCol(this->playerid, text, color1, color2);
}

bool CPlayer::SetPVarInt(const char * varname, int value) {
  return sampgdk::SetPVarInt(this->playerid, varname, value);
}

int CPlayer::GetPVarInt(const char * varname) {
  return sampgdk::GetPVarInt(this->playerid, varname);
}

bool CPlayer::SetPVarString(const char * varname, const char * value) {
  return sampgdk::SetPVarString(this->playerid, varname, value);
}

bool CPlayer::GetPVarString(const char * varname, char * value, int size) {
  return sampgdk::GetPVarString(this->playerid, varname, value, size);
}

bool CPlayer::SetPVarFloat(const char * varname, float value) {
  return sampgdk::SetPVarFloat(this->playerid, varname, value);
}

float CPlayer::GetPVarFloat(const char * varname) {
  return sampgdk::GetPVarFloat(this->playerid, varname);
}

bool CPlayer::DeletePVar(const char * varname) {
  return sampgdk::DeletePVar(this->playerid, varname);
}

int CPlayer::GetPVarsUpperIndex() {
  return sampgdk::GetPVarsUpperIndex(this->playerid);
}

bool CPlayer::GetPVarNameAtIndex(int index, char * varname, int size) {
  return sampgdk::GetPVarNameAtIndex(this->playerid, index, varname, size);
}

int CPlayer::GetPVarType(const char * varname) {
  return sampgdk::GetPVarType(this->playerid, varname);
}

bool CPlayer::SetChatBubble(const char * text, int color, float drawdistance, int expiretime) {
  return sampgdk::SetPlayerChatBubble(this->playerid, text, color, drawdistance, expiretime);
}

bool CPlayer::PutInVehicle(int vehicleid, int seatid) {
  return sampgdk::PutPlayerInVehicle(this->playerid, vehicleid, seatid);
}

int CPlayer::GetVehicleID() {
  return sampgdk::GetPlayerVehicleID(this->playerid);
}

int CPlayer::GetVehicleSeat() {
  return sampgdk::GetPlayerVehicleSeat(this->playerid);
}

bool CPlayer::RemoveFromVehicle() {
  return sampgdk::RemovePlayerFromVehicle(this->playerid);
}

bool CPlayer::ToggleControllable(bool toggle) {
  return sampgdk::TogglePlayerControllable(this->playerid, toggle);
}

bool CPlayer::PlaySound(int soundid, float x, float y, float z) {
  return sampgdk::PlayerPlaySound(this->playerid, soundid, x, y, z);
}

bool CPlayer::ApplyAnimation(const char * animlib, const char * animname, float fDelta, bool loop, bool lockx, bool locky, bool freeze, int time, bool forcesync) {
  return sampgdk::ApplyAnimation(this->playerid, animlib, animname, fDelta, loop, lockx, locky, freeze, time, forcesync);
}

bool CPlayer::ClearAnimations(bool forcesync) {
  return sampgdk::ClearAnimations(this->playerid, forcesync);
}

int CPlayer::GetAnimationIndex() {
  return sampgdk::GetPlayerAnimationIndex(this->playerid);
}

int CPlayer::GetSpecialAction() {
  return sampgdk::GetPlayerSpecialAction(this->playerid);
}

bool CPlayer::SetSpecialAction(int actionid) {
  return sampgdk::SetPlayerSpecialAction(this->playerid, actionid);
}

bool CPlayer::DisableRemoteVehicleCollisions(bool disable) {
  return sampgdk::DisableRemoteVehicleCollisions(this->playerid, disable);
}

bool CPlayer::SetCheckpoint(float x, float y, float z, float size) {
  return sampgdk::SetPlayerCheckpoint(this->playerid, x, y, z, size);
}

bool CPlayer::DisableCheckpoint() {
  return sampgdk::DisablePlayerCheckpoint(this->playerid);
}

bool CPlayer::SetRaceCheckpoint(int type, float x, float y, float z, float nextx, float nexty, float nextz, float size) {
  return sampgdk::SetPlayerRaceCheckpoint(this->playerid, type, x, y, z, nextx, nexty, nextz, size);
}

bool CPlayer::DisableRaceCheckpoint() {
  return sampgdk::DisablePlayerRaceCheckpoint(this->playerid);
}

bool CPlayer::SetWorldBounds(float x_max, float x_min, float y_max, float y_min) {
  return sampgdk::SetPlayerWorldBounds(this->playerid, x_max, x_min, y_max, y_min);
}

bool CPlayer::SetMarker(int showplayerid, int color) {
  return sampgdk::SetPlayerMarkerForPlayer(this->playerid, showplayerid, color);
}

bool CPlayer::ShowNameTag(int showplayerid, bool show) {
  return sampgdk::ShowPlayerNameTagForPlayer(this->playerid, showplayerid, show);
}

bool CPlayer::SetMapIcon(int iconid, float x, float y, float z, int markertype, int color, int style) {
  return sampgdk::SetPlayerMapIcon(this->playerid, iconid, x, y, z, markertype, color, style);
}

bool CPlayer::RemoveMapIcon(int iconid) {
  return sampgdk::RemovePlayerMapIcon(this->playerid, iconid);
}

bool CPlayer::AllowTeleport(bool allow) {
  return sampgdk::AllowPlayerTeleport(this->playerid, allow);
}

bool CPlayer::SetCameraPos(float x, float y, float z) {
  return sampgdk::SetPlayerCameraPos(this->playerid, x, y, z);
}

bool CPlayer::SetCameraLookAt(float x, float y, float z, int cut) {
  return sampgdk::SetPlayerCameraLookAt(this->playerid, x, y, z, cut);
}

bool CPlayer::SetCameraBehindPlayer() {
  return sampgdk::SetCameraBehindPlayer(this->playerid);
}

bool CPlayer::GetCameraPos(float * x, float * y, float * z) {
  return sampgdk::GetPlayerCameraPos(this->playerid, x, y, z);
}

bool CPlayer::GetCameraFrontVector(float * x, float * y, float * z) {
  return sampgdk::GetPlayerCameraFrontVector(this->playerid, x, y, z);
}

int CPlayer::GetCameraMode() {
  return sampgdk::GetPlayerCameraMode(this->playerid);
}

bool CPlayer::EnableCameraTarget(bool enable) {
  return sampgdk::EnablePlayerCameraTarget(this->playerid, enable);
}

int CPlayer::GetCameraTargetObject() {
  return sampgdk::GetPlayerCameraTargetObject(this->playerid);
}

int CPlayer::GetCameraTargetVehicle() {
  return sampgdk::GetPlayerCameraTargetVehicle(this->playerid);
}

int CPlayer::GetCameraTarget() {
  return sampgdk::GetPlayerCameraTargetPlayer(this->playerid);
}

int CPlayer::GetCameraTargetActor() {
  return sampgdk::GetPlayerCameraTargetActor(this->playerid);
}

float CPlayer::GetCameraAspectRatio() {
  return sampgdk::GetPlayerCameraAspectRatio(this->playerid);
}

float CPlayer::GetCameraZoom() {
  return sampgdk::GetPlayerCameraZoom(this->playerid);
}

bool CPlayer::AttachCameraToObject(int objectid) {
  return sampgdk::AttachCameraToObject(this->playerid, objectid);
}

bool CPlayer::AttachCameraToPlayerObject(int playerobjectid) {
  return sampgdk::AttachCameraToPlayerObject(this->playerid, playerobjectid);
}

bool CPlayer::InterpolateCameraPos(float FromX, float FromY, float FromZ, float ToX, float ToY, float ToZ, int time, int cut) {
  return sampgdk::InterpolateCameraPos(this->playerid, FromX, FromY, FromZ, ToX, ToY, ToZ, time, cut);
}

bool CPlayer::InterpolateCameraLookAt(float FromX, float FromY, float FromZ, float ToX, float ToY, float ToZ, int time, int cut) {
  return sampgdk::InterpolateCameraLookAt(this->playerid, FromX, FromY, FromZ, ToX, ToY, ToZ, time, cut);
}

bool CPlayer::IsConnected() {
  return sampgdk::IsPlayerConnected(this->playerid);
}

bool CPlayer::IsInVehicle(int vehicleid) {
  return sampgdk::IsPlayerInVehicle(this->playerid, vehicleid);
}

bool CPlayer::IsInAnyVehicle() {
  return sampgdk::IsPlayerInAnyVehicle(this->playerid);
}

bool CPlayer::IsInCheckpoint() {
  return sampgdk::IsPlayerInCheckpoint(this->playerid);
}

bool CPlayer::IsInRaceCheckpoint() {
  return sampgdk::IsPlayerInRaceCheckpoint(this->playerid);
}

bool CPlayer::SetVirtualWorld(int worldid) {
  return sampgdk::SetPlayerVirtualWorld(this->playerid, worldid);
}

int CPlayer::GetVirtualWorld() {
  return sampgdk::GetPlayerVirtualWorld(this->playerid);
}

bool CPlayer::EnableStuntBonus(bool enable) {
  return sampgdk::EnableStuntBonusForPlayer(this->playerid, enable);
}

bool CPlayer::ToggleSpectating(bool toggle) {
  return sampgdk::TogglePlayerSpectating(this->playerid, toggle);
}

bool CPlayer::Spectate(int targetplayerid, int mode) {
  return sampgdk::PlayerSpectatePlayer(this->playerid, targetplayerid, mode);
}

bool CPlayer::SpectateVehicle(int targetvehicleid, int mode) {
  return sampgdk::PlayerSpectateVehicle(this->playerid, targetvehicleid, mode);
}

bool CPlayer::StartRecordingData(int recordtype, const char * recordname) {
  return sampgdk::StartRecordingPlayerData(this->playerid, recordtype, recordname);
}

bool CPlayer::StopRecordingData() {
  return sampgdk::StopRecordingPlayerData(this->playerid);
}

bool CPlayer::CreateExplosion(float X, float Y, float Z, int type, float Radius) {
  return sampgdk::CreateExplosionForPlayer(this->playerid, X, Y, Z, type, Radius);
}


PLUGIN_EXPORT bool PLUGIN_CALL OnDialogResponse(int playerid, int dialogid, int response, int listitem, const char * inputtext)
{
	CPlayer * player = CPlayerManager::get()[playerid];
	if (player) {
		switch (player->dialogCallback.index()) {
		case 0:
			std::get<0>(player->dialogCallback)(response == 1);
			break;
		case 1:
			std::get<1>(player->dialogCallback)(listitem);
			break;
		case 2:
			std::get<2>(player->dialogCallback)(inputtext);
			break;
		}
	}
	return true;
}
