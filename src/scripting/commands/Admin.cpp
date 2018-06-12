#include "stdafx.h"

std::vector<CVehicle*> adminVehicles;

Event::CPlayerCommand veh("/veh", [](CPlayer* player, const std::vector<std::string> &params) -> bool {
	if (params.size() < 3) {
		player->SendMessage(0xAAAAAAFF, "  Используйте: /veh [model] [color1] [color2]");
		return true;
	}

	int vehModel, color1, color2;
	try {
		vehModel = std::stoi(params[0]);
		color1 = std::stoi(params[1]);
		color2 = std::stoi(params[2]);
	}
	catch (...) {
		player->SendMessage(0xAAAAAAFF, "  Используйте: /veh [model 400-611] [color1 0-255] [color2 0-255]");
		return true;
	}

	if (vehModel < 400 || vehModel > 611) {
		player->SendMessage(0xAAAAAAFF, "  Используйте: /veh [model " C_HIGHLIGHT "400-611" C_GRAY "] [color1 0-255] [color2 0-255]");
		return true;
	}

	if (color1 < 0 || color1 > 255) {
		player->SendMessage(0xAAAAAAFF, "  Используйте: /veh [model 400-611] [color1 " C_HIGHLIGHT "0-255" C_GRAY "] [color2 0-255]");
		return true;
	}

	if (color2 < 0 || color2 > 255) {
		player->SendMessage(0xAAAAAAFF, "  Используйте: /veh [model 400-611] [color1 0-255] [color2 " C_HIGHLIGHT "0-255" C_GRAY "]");
		return true;
	}

	if (adminVehicles.size() >= 20) {
		player->SendMessage(0xAA0000FF, "  Ошибка: Достигнут лимит на создание транспорта");
		return true;
	}

	float x, y, z, r;
	player->GetPos(x, y, z);
	player->GetFacingAngle(r);

	CVehicle *veh = CVehicleFactory::get().Create(vehModel, x, y, z, r, color1, color2);
	player->PutInVehicle(veh, 0);
	adminVehicles.push_back(veh);
	return true;
});

bool ShowAdminVehicles(CPlayer* player) {
	std::stringstream ss;
	bool isFirst = true;
	for (auto v : adminVehicles) {
		if (!isFirst)
			ss << "\n";
		else
			isFirst = false;

		ss << "[ " << v->GetID() << " ] " << v->GetName();
	}

	player->ShowListboxDialog(C_AERO "Удаление созданного транспорта", ss.str().c_str(), "Удалить", "Закрыть", [=](int selected) -> bool {
		CVehicle* toDelete = adminVehicles[selected];
		adminVehicles.erase(adminVehicles.begin() + selected);
		CVehicleFactory::get().Destroy(toDelete);
		if (adminVehicles.size() > 0) {
			return ShowAdminVehicles(player);
		}
		return true;
	});
	return true;
}

Event::CPlayerCommand vehs("/vehs", [](CPlayer* player) -> bool {
	if (adminVehicles.size() > 0) {
		ShowAdminVehicles(player);
	}
	else {
		player->SendMessage(0xAAAAAAFF, "  Транспортных средств созданных администраторами сейчас нет");
	}
	return true;
});

float x, y, z;

Event::CPlayerCommand tp("/tp", [](CPlayer* player) -> bool {
	player->SetInterior(5);
	player->GetPos(x, y, z);
	player->SetPos(22.7783, 1404.96, 1083.45);
	return true;
});

Event::CPlayerCommand tpb("/tpb", [](CPlayer* player) -> bool {
	player->SetInterior(0);
	player->SetPos(x, y, z);
	return true;
});


