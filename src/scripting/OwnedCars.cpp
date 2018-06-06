#include "stdafx.h"

Event::CGameInited init([]() -> bool {
	CActor* seller = CActorFactory::get().Create(240, -1664.9186, 1206.2539, 7.2546, 324.7190, false, 255.f);
	seller->OnDamaged([](CPlayer* player, float amount, int weapon, int bodypart) -> void {
		player->SetWantedLevel(player->GetWantedLevel() + 1);
	});

	CPickup* buyCarPickup = CPickupFactory::get().Create(1274, 1, -1663.6060f, 1208.4708f, 7.2546f);
	buyCarPickup->OnPickedUp([](CPlayer* player) {
		player->ShowListboxDialog(C_AZURE"  Добро пожаловать в " C_AWESOME " Otto's Autos", C_AMBER "Выберите интересующий вас класс транспорта из списка ниже:" C_WHITE "\nСпорт\nКупе\nСемейная", "Перейти", "Выход", [](int selected) -> bool {

			return true;
		});
	});
	return false;
});