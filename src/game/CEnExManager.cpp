#include "stdafx.h"

void Game::CEnExManager::Parse(const std::string & line)
{
	CEnterExit *enex = new CEnterExit(line);
	if (enex->markerFlags & 1000) {
		Log::Debug << "Burglar house \"" << enex->interiorName << "\" loaded" << std::endl;
	}
	if (enex->interior != 0) {
		pool.push_back(enex);
		poolByName.emplace(std::pair<std::string, CEnterExit*>(enex->GetName(), enex));
	}
}
