#include "stdafx.h"

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

