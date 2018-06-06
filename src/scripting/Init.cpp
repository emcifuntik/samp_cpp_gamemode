#include "stdafx.h"

Event::CGameInited GameInited([]() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Log& log = Log::get();
	log.AddOut(&std::wcout);
	sampgdk::SetGameModeText("C++ Private");
	sampgdk::DisableInteriorEnterExits();
	sampgdk::EnableStuntBonusForAll(false);

	//sampgdk::SetTimer(1000, true, WorldTimeChanger, 0);

	CDataBase::get().Init();

	CVehicleFactory::get().Create(487, 0, 0, 4.0f, 0, 0, 0);
	return false;
});