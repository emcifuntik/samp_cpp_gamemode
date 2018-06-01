#include "stdafx.h"

Log::Log_Info Log::Info; Log::Log_Error Log::Error; Log::Log_Debug Log::Debug;

bool HelpMessage(CPlayer * player, std::vector<std::string> params) {
	return true;
}

//void SAMPGDK_CALL WorldTimeChanger(int timerid, void *params) {
//	int hours, minutes;
//	GetInGameTime(hours, minutes);
//
//	for (int i = 0; i < CPlayerManager::Get().GetMaxID(); ++i) {
//		if (CPlayerManager::Get().IsConnected(i)) {
//			CPlayer * player = CPlayerManager::Get()[i];
//			player->SetTime(hours, minutes);
//		}
//	}
//}

PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeInit() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Log& log = Log::get();
	log.AddOut(&std::wcout);
	sampgdk::SetGameModeText("C++ Private");
	//sampgdk::SetTimer(1000, true, WorldTimeChanger, 0);

	CDataBase::Get();

	//CCommandProcessor::Get().Add("/help", HelpMessage);
	return true;
}
