#include "stdafx.h"

Event::CRconCommand wipe("wipedata", [](const std::string& params) -> bool {
	DB::CPlayerData defaultPlayerData;
	defaultPlayerData.DropTable();
	defaultPlayerData.CreateTable();
	Log::Info << "������ ������� �������." << std::endl;
	//Log::Debug << defaultPlayerData.CreateTable() << std::endl;
	return true;
});