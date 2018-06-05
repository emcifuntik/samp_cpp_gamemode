#include "stdafx.h"

Event::CPlayerConnect Connect([](CPlayer* player) {
	player->SetSpawnInfo(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	player->SendMessage(0x00AA00FF, "Добро пожаловать");
	return true;
});

Event::CPlayerDisconnect Disconnect([](CPlayer * player, int reason) {
	if (player->loggedIn) {
		float x, y, z, a;
		player->GetPos(&x, &y, &z);
		player->GetFacingAngle(&a);
		player->lastPosition = { x, y, z };
		player->heading = a;
		CDataBase::get().SaveUser(player);
	}
	return true;
});

Event::CPlayerSpawn Spawn([](CPlayer * player) {
	if (!player->loggedIn) {
		int hours, minutes;
		GetInGameTime(hours, minutes);
		player->SetTime(hours, minutes);
		player->ToggleSpectating(true);

		char playerName[MAX_PLAYER_NAME + 1];
		player->GetName(playerName, MAX_PLAYER_NAME + 1);

		bool registered = CDataBase::get().UserRegistered(playerName);

		if (!registered) {
			player->ShowPasswordDialog("{FFFFFF}Добро пожаловать на {00AA00}YourDream Roleplay", "Введите пароль чтобы зарегистрироваться на сервере!", "Далее", DIALOG_NO_BUTTON, [player, playerName](const char* password) {
				bool isRegistered = CDataBase::get().RegisterUser(playerName, password);
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
				bool loggedIn = CDataBase::get().LoginUser(player, playerName, password);
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
	return true;
});
