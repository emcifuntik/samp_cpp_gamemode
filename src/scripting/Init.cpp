#include "stdafx.h"

Event::CGameInited GameInited([]() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Log& log = Log::get();
	log.AddOut(&std::wcout);
	sampgdk::SetGameModeText("C++ Private Development");
	//sampgdk::SetTimer(1000, true, WorldTimeChanger, 0);

	CDataBase::get().Init();

	CVehicleFactory::get().Create(520, 0, 0, 70, 0, 0, 0);
	return true;
});