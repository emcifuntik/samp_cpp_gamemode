#include "stdafx.h"
#include "CVehicle.h"


CVehicle::CVehicle(int model, float x, float y, float z, float a, int color1, int color2, int respawnDelay, bool addSiren)
{
	id = sampgdk::CreateVehicle(model, x, y, z, a, color1, color2, respawnDelay, addSiren);
}


CVehicle::~CVehicle()
{
	sampgdk::DestroyVehicle(this->id);
}

bool CVehicle::IsValid() {
	return sampgdk::IsValidVehicle(this->id);
}

float CVehicle::GetDistanceFromPoint(float x, float y, float z) {
	return sampgdk::GetVehicleDistanceFromPoint(this->id, x, y, z);
}

bool CVehicle::IsStreamedIn(int forplayerid) {
	return sampgdk::IsVehicleStreamedIn(this->id, forplayerid);
}

bool CVehicle::GetPos(float * x, float * y, float * z) {
	return sampgdk::GetVehiclePos(this->id, x, y, z);
}

bool CVehicle::SetPos(float x, float y, float z) {
	return sampgdk::SetVehiclePos(this->id, x, y, z);
}

bool CVehicle::GetZAngle(float * z_angle) {
	return sampgdk::GetVehicleZAngle(this->id, z_angle);
}

bool CVehicle::GetRotationQuat(float * w, float * x, float * y, float * z) {
	return sampgdk::GetVehicleRotationQuat(this->id, w, x, y, z);
}

bool CVehicle::SetZAngle(float z_angle) {
	return sampgdk::SetVehicleZAngle(this->id, z_angle);
}

bool CVehicle::SetParamsForPlayer(int playerid, int objective, int doorslocked) {
	return sampgdk::SetVehicleParamsForPlayer(this->id, playerid, objective, doorslocked);
}

bool CVehicle::ManualEngineAndLights() {
	return sampgdk::ManualVehicleEngineAndLights();
}

bool CVehicle::SetParamsEx(int engine, int lights, int alarm, int doors, int bonnet, int boot, int objective) {
	return sampgdk::SetVehicleParamsEx(this->id, engine, lights, alarm, doors, bonnet, boot, objective);
}

bool CVehicle::GetParamsEx(int * engine, int * lights, int * alarm, int * doors, int * bonnet, int * boot, int * objective) {
	return sampgdk::GetVehicleParamsEx(this->id, engine, lights, alarm, doors, bonnet, boot, objective);
}

int CVehicle::GetParamsSirenState() {
	return sampgdk::GetVehicleParamsSirenState(this->id);
}

bool CVehicle::SetParamsCarDoors(int driver, int passenger, int backleft, int backright) {
	return sampgdk::SetVehicleParamsCarDoors(this->id, driver, passenger, backleft, backright);
}

bool CVehicle::GetParamsCarDoors(int * driver, int * passenger, int * backleft, int * backright) {
	return sampgdk::GetVehicleParamsCarDoors(this->id, driver, passenger, backleft, backright);
}

bool CVehicle::SetParamsCarWindows(int driver, int passenger, int backleft, int backright) {
	return sampgdk::SetVehicleParamsCarWindows(this->id, driver, passenger, backleft, backright);
}

bool CVehicle::GetParamsCarWindows(int * driver, int * passenger, int * backleft, int * backright) {
	return sampgdk::GetVehicleParamsCarWindows(this->id, driver, passenger, backleft, backright);
}

bool CVehicle::SetToRespawn() {
	return sampgdk::SetVehicleToRespawn(this->id);
}

bool CVehicle::LinkToInterior(int interiorid) {
	return sampgdk::LinkVehicleToInterior(this->id, interiorid);
}

bool CVehicle::AddComponent(int componentid) {
	return sampgdk::AddVehicleComponent(this->id, componentid);
}

bool CVehicle::RemoveComponent(int componentid) {
	return sampgdk::RemoveVehicleComponent(this->id, componentid);
}

bool CVehicle::ChangeColor(int color1, int color2) {
	return sampgdk::ChangeVehicleColor(this->id, color1, color2);
}

bool CVehicle::ChangePaintjob(int paintjobid) {
	return sampgdk::ChangeVehiclePaintjob(this->id, paintjobid);
}

bool CVehicle::SetHealth(float health) {
	return sampgdk::SetVehicleHealth(this->id, health);
}

bool CVehicle::GetHealth(float * health) {
	return sampgdk::GetVehicleHealth(this->id, health);
}

bool CVehicle::AttachTrailer(int trailerid) {
	return sampgdk::AttachTrailerToVehicle(trailerid, this->id);
}

bool CVehicle::DetachTrailer() {
	return sampgdk::DetachTrailerFromVehicle(this->id);
}

bool CVehicle::IsTrailerAttached() {
	return sampgdk::IsTrailerAttachedToVehicle(this->id);
}

int CVehicle::GetTrailer() {
	return sampgdk::GetVehicleTrailer(this->id);
}

bool CVehicle::SetNumberPlate(const char * numberplate) {
	return sampgdk::SetVehicleNumberPlate(this->id, numberplate);
}

int CVehicle::GetModel() {
	return sampgdk::GetVehicleModel(this->id);
}

int CVehicle::GetComponentInSlot(int slot) {
	return sampgdk::GetVehicleComponentInSlot(this->id, slot);
}

int CVehicle::GetComponentType(int component) {
	return sampgdk::GetVehicleComponentType(component);
}

bool CVehicle::Repair() {
	return sampgdk::RepairVehicle(this->id);
}

bool CVehicle::GetVelocity(float * X, float * Y, float * Z) {
	return sampgdk::GetVehicleVelocity(this->id, X, Y, Z);
}

bool CVehicle::SetVelocity(float X, float Y, float Z) {
	return sampgdk::SetVehicleVelocity(this->id, X, Y, Z);
}

bool CVehicle::SetAngularVelocity(float X, float Y, float Z) {
	return sampgdk::SetVehicleAngularVelocity(this->id, X, Y, Z);
}

bool CVehicle::GetDamageStatus(int * panels, int * doors, int * lights, int * tires) {
	return sampgdk::GetVehicleDamageStatus(this->id, panels, doors, lights, tires);
}

bool CVehicle::UpdateDamageStatus(int panels, int doors, int lights, int tires) {
	return sampgdk::UpdateVehicleDamageStatus(this->id, panels, doors, lights, tires);
}

bool CVehicle::SetVirtualWorld(int worldid) {
	return sampgdk::SetVehicleVirtualWorld(this->id, worldid);
}

int CVehicle::GetVirtualWorld() {
	return sampgdk::GetVehicleVirtualWorld(this->id);
}

bool CVehicle::GetModelInfo(int model, int infotype, float * X, float * Y, float * Z) {
	return sampgdk::GetVehicleModelInfo(model, infotype, X, Y, Z);
}