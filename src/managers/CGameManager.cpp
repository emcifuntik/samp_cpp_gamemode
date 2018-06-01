#include "stdafx.h"

bool CGameManager::Init()
{
	for (auto it = this->initHandlers.begin(); it < this->initHandlers.end(); ++it) {
		if ((*it)()) {
			return true;
		}
	}
	return false;
}
bool CGameManager::OnInit(std::function<bool()> callback)
{
	this->initHandlers.push_back(callback);
	return true;
}

bool CGameManager::Exit()
{
	for (auto it = this->exitHandlers.begin(); it < this->exitHandlers.end(); ++it) {
		if ((*it)()) {
			return true;
		}
	}
	return false;
}

bool CGameManager::OnExit(std::function<bool()> callback)
{
	this->exitHandlers.push_back(callback);
	return true;
}



PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeInit() { return CGameManager::get().Init(); }
PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeExit() { return CGameManager::get().Exit(); }
