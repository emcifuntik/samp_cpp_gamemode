#include "stdafx.h"

Log::Log_Info Log::Info; Log::Log_Error Log::Error; Log::Log_Debug Log::Debug;

void GetInGameTime(int& hours, int& minutes) {
	int currGameTime = time(NULL) % 3600;
	hours = currGameTime / 150;
	minutes = int((currGameTime % 150) / 2.5f);
}

bool PlayerConnect(CPlayer * player) {
	player->SetSpawnInfo(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	player->SendMessage(0x00AA00FF, "Добро пожаловать");
	return true;
}

bool PlayerDisconnect(CPlayer * player, int reason) {
	if (player->loggedIn) {
		float x, y, z, a;
		player->GetPos(&x, &y, &z);
		player->GetFacingAngle(&a);
		player->lastPosition = { x, y, z };
		player->heading = a;
		CDataBase::Get().SaveUser(player);
	}
	return true;
}

bool PlayerSpawn(CPlayer * player) {
	if (!player->loggedIn) {
		int hours, minutes;
		GetInGameTime(hours, minutes);
		player->SetTime(hours, minutes);
		player->ToggleSpectating(true);

		char playerName[24];
		player->GetName(playerName, 24);

		bool registered = CDataBase::Get().UserRegistered(playerName);

		if (!registered) {
			player->ShowPasswordDialog("{FFFFFF}Добро пожаловать на {00AA00}YourDream Roleplay", "Введите пароль чтобы зарегистрироваться на сервере!", "Далее", DIALOG_NO_BUTTON, [player, playerName](const char* password) {
				bool isRegistered = CDataBase::Get().RegisterUser(playerName, password);
				if (isRegistered) {
					player->SendMessage(0x00FF00FF, " Вы успешно зарегистрировались на сервере");
					player->loggedIn = true;
					player->ToggleSpectating(false);
				}
				return true;
			});
		}
		else {
			player->ShowPasswordDialog("{FFFFFF}Добро пожаловать на {00AA00}YourDream Roleplay", "Вы зарегистрированы.\nВведите свой пароль!", "Войти", DIALOG_NO_BUTTON, [player, playerName](const char* password) {
				bool loggedIn = CDataBase::Get().LoginUser(player, playerName, password);
				if (!loggedIn) {
					player->SendMessage(0x00FF00FF, " Пароль введён не верно. Вы были кикнуты с сервера");
				}
				else {
					player->SendMessage(0x00FF00FF, " Вы успешно вошли на сервер");
					player->loggedIn = true;
					player->ToggleSpectating(false);
					player->SetPos(player->lastPosition.x, player->lastPosition.y, player->lastPosition.z);
					player->SetFacingAngle(player->heading);
				}
				
				return true;
			});
		}
	}
	else {

	}
	return true;
}

bool HelpMessage(CPlayer * player, std::vector<std::string> params) {
	return true;
}

void SAMPGDK_CALL WorldTimeChanger(int timerid, void *params) {
	int hours, minutes;
	GetInGameTime(hours, minutes);

	for (int i = 0; i < CPlayerManager::Get().GetMaxID(); ++i) {
		if (CPlayerManager::Get().IsConnected(i)) {
			CPlayer * player = CPlayerManager::Get()[i];
			player->SetTime(hours, minutes);
		}
	}
}

PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeInit() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Log& log = Log::Instance();
	log.AddOut(&std::wcout);
	sampgdk::SetGameModeText("C++ Private");
	sampgdk::SetTimer(1000, true, WorldTimeChanger, 0);

	CDataBase::Get();

	CCommandProcessor::Get().Add("/help", HelpMessage);

	CPlayerManager::Get().OnConnect(PlayerConnect);
	CPlayerManager::Get().OnDisconnect(PlayerDisconnect);
	CPlayerManager::Get().OnSpawn(PlayerSpawn);
	return true;
}
