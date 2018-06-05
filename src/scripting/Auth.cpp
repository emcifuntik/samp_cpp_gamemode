#include "stdafx.h"

Event::CPlayerConnect Connect([](CPlayer* player) {
	player->SetSpawnInfo(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	player->SendMessage(0x00AA00FF, "����� ����������");
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
			player->ShowPasswordDialog("{FFFFFF}����� ���������� �� {00AA00}YourDream Roleplay", "������� ������ ����� ������������������ �� �������!", "�����", DIALOG_NO_BUTTON, [player, playerName](const char* password) {
				bool isRegistered = CDataBase::get().RegisterUser(playerName, password);
				if (isRegistered) {
					player->SendMessage(0x00FF00FF, " �� ������� ������������������ �� �������");
					player->loggedIn = true;
					player->ToggleSpectating(false);
				}
				return true;
			});
		}
		else {
			player->ShowPasswordDialog("{FFFFFF}����� ���������� �� {00AA00}YourDream Roleplay", "�� ����������������.\n������� ���� ������!", "�����", DIALOG_NO_BUTTON, [player, playerName](const char* password) {
				bool loggedIn = CDataBase::get().LoginUser(player, playerName, password);
				if (!loggedIn) {
					player->SendMessage(0x00FF00FF, " ������ ����� �� �����. �� ���� ������� � �������");
				}
				else {
					player->SendMessage(0x00FF00FF, " �� ������� ����� �� ������");
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
