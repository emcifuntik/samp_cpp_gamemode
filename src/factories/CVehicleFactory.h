#pragma once

class CVehicleFactory: public CSingleton<CVehicleFactory> {
	std::vector<CVehicle*> pool;
public:
	CVehicle * Create(int model, float x, float y, float z, float a, int color1, int color2, int respawnDelay = 0, bool addSiren = false);
	bool Destroy(CVehicle* vehicle);
	void DestroyAll();
};