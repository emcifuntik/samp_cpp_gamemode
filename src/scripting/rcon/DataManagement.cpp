#include "stdafx.h"

Event::CRconCommand wipe("wipedata", [](const std::string& params) -> bool {
	DB::CPlayerData defaultPlayerData;
	defaultPlayerData.DropTable();
	defaultPlayerData.CreateTable();
	sampgdk::logprintf("Data successfully wiped.");
	//Log::Debug << defaultPlayerData.CreateTable() << std::endl;
	return true;
});