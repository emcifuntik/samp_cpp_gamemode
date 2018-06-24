#include "stdafx.h"

Event::CPlayerConnect Connect([](CPlayer* player) {
	player->ToggleSpectating(true);
	player->SetSpawnInfo(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	player->SendMessage(0x00AA00FF, "Добро пожаловать");
	
	int hours, minutes;
	GetInGameTime(hours, minutes);
	player->SetTime(hours, minutes);
	player->ToggleSpectating(true);

	char playerName[MAX_PLAYER_NAME + 1];
	player->GetName(playerName, MAX_PLAYER_NAME + 1);

	bool registered = player->Exists(playerName);

	if (!registered) {
		player->ShowPasswordDialog("{FFFFFF}Добро пожаловать на {00AA00}YourDream Roleplay", "Введите пароль чтобы зарегистрироваться на сервере!", "Далее", [player, playerName](const char* password) {
			bool isRegistered = player->Register(playerName, jhash(password));
			if (isRegistered) {
				player->SendMessage(0x00FF00FF, " Вы успешно зарегистрировались на сервере");
				player->loggedIn = true;
				player->ToggleSpectating(false);
			}
			return true;
		});
	}
	else {
		player->ShowPasswordDialog("{FFFFFF}Добро пожаловать на {00AA00}YourDream Roleplay", "Вы зарегистрированы.\nВведите свой пароль!", "Войти", [player, playerName](const char* password) {
			bool loggedIn = player->Auth(playerName, jhash(password));
			if (!loggedIn) {
				player->SendMessage(0x00FF00FF, " Пароль введён не верно. Вы были кикнуты с сервера");
				//player->Kick
			}
			else {
				player->SendMessage(0x00FF00FF, " Вы успешно вошли на сервер");
				player->loggedIn = true;
				player->ToggleSpectating(false);
				player->SetPos(player->posX(), player->posY(), player->posZ());
				player->SetFacingAngle(player->heading());
			}

			return true;
		});
	}
	return false;
});

Event::CPlayerDisconnect Disconnect([](CPlayer * player, int reason) {
	if (player->loggedIn) {
		float x, y, z, a;
		player->GetPos(x, y, z);
		player->GetFacingAngle(a);

		player->posX = x;
		player->posY = y;
		player->posZ = z;
		player->heading = a;
		player->Save();
	}
	return false;
});

Event::CPlayerSpawn Spawn([](CPlayer * player) {
	
	return false;
});
