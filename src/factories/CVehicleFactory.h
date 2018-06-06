#pragma once

class CVehicleFactory: public CSingleton<CVehicleFactory> {
	std::list<CVehicle*> pool;
public:
	CVehicle * Create(int model, float x, float y, float z, float a, int color1, int color2, int respawnDelay = 0, bool addSiren = false);
	bool Destroy(CVehicle* vehicle);
	void DestroyAll();
};