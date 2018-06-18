#include "stdafx.h"

std::vector<CVehicle*> adminVehicles;

Event::CPlayerCommand veh("/veh", [](CPlayer* player, const std::vector<std::string> &params) -> bool {
	if (params.size() < 3) {
		player->SendMessage(0xAAAAAAFF, "  �����������: /veh [model] [color1] [color2]");
		return true;
	}

	int vehModel, color1, color2;
	try {
		vehModel = std::stoi(params[0]);
		color1 = std::stoi(params[1]);
		color2 = std::stoi(params[2]);
	}
	catch (...) {
		player->SendMessage(0xAAAAAAFF, "  �����������: /veh [model 400-611] [color1 0-255] [color2 0-255]");
		return true;
	}

	if (vehModel < 400 || vehModel > 611) {
		player->SendMessage(0xAAAAAAFF, "  �����������: /veh [model " C_HIGHLIGHT "400-611" C_GRAY "] [color1 0-255] [color2 0-255]");
		return true;
	}

	if (color1 < 0 || color1 > 255) {
		player->SendMessage(0xAAAAAAFF, "  �����������: /veh [model 400-611] [color1 " C_HIGHLIGHT "0-255" C_GRAY "] [color2 0-255]");
		return true;
	}

	if (color2 < 0 || color2 > 255) {
		player->SendMessage(0xAAAAAAFF, "  �����������: /veh [model 400-611] [color1 0-255] [color2 " C_HIGHLIGHT "0-255" C_GRAY "]");
		return true;
	}

	if (adminVehicles.size() >= 20) {
		player->SendMessage(0xAA0000FF, "  ������: ��������� ����� �� �������� ����������");
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

	player->ShowListboxDialog(C_AERO "�������� ���������� ����������", ss.str().c_str(), "�������", "�������", [=](int selected) -> bool {
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
		player->SendMessage(0xAAAAAAFF, "  ������������ ������� ��������� ���������������� ������ ���");
	}
	return true;
});

float x, y, z;

int lastSelected = -1;

Event::CPlayerCommand tplist("/tplist", [](CPlayer* player) -> bool {

	auto vec = Game::CEnExManager::get().GetVector();

	std::stringstream ss;
	ss << "�������� ����� ��� ���������";
	for (int i = 0; i < vec.size(); ++i) {
		ss << "\n";
		if (i == lastSelected)
			ss << C_AFRICAN_VIOLET;
		ss << vec[i]->GetName();
		if (i == lastSelected)
			ss << C_WHITE;
	}

	player->ShowListboxDialog(" * �������� � �����", ss.str().c_str(), "�������", "������", [=](int selected) -> bool {
		if (selected == 0)
			return true;
		lastSelected = selected - 1;

		Game::CEnterExit* enex = Game::CEnExManager::get()[selected - 1];
		if (enex != nullptr) {
			if (player->GetInterior() == 0) {
				player->GetPos(x, y, z);
			}
			player->SetInterior(enex->GetInterior());
			player->SetPos(enex->GetExitPos() + CVector3f({ 0.f, 0.f, 1.0f }));
			player->SetFacingAngle(enex->GetExitRotation());
		}
		return true;
	});
	return true;
});

Event::CPlayerCommand tpb("/tpb", [](CPlayer* player) -> bool {
	player->SetInterior(0);
	player->SetPos(x, y, z);
	return true;
});


