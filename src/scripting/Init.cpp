#include "stdafx.h"

Event::CGameInited GameInited([]() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Log& log = Log::get();
	log.AddOut(&std::wcout);
	sampgdk::SetGameModeText("C++ Private");
	sampgdk::DisableInteriorEnterExits();
	sampgdk::EnableStuntBonusForAll(false);

	/*Log::Debug << "Loading IPLs..." << std::endl;
	Game::CGameDataLoader::get().LoadIPLs("./gamedata/maps");
	Log::Debug << (size_t)Game::CEnExManager::get() << " enexes loaded" << std::endl;

	auto intVectors = Game::CEnExManager::get().GetVector();*/

	//for (int i = 0; i < intVectors.size(); ++i) {
	//	if (intVectors[i]->GetInterior() != 0) {
	//		auto exitPickupPos = intVectors[i]->GetEnterPos();

	//		auto pickup = CPickupFactory::get().Create(1318, 1, exitPickupPos.x, exitPickupPos.y, exitPickupPos.z + 0.5f, -1, intVectors[i]->GetInterior());
	//		pickup->OnPickedUp([=](CPlayer* player) -> void {
	//			/*if (player->GetInterior() != 0) {
	//				player->MoveBack();
	//				player->SetInterior(0);
	//			}*/
	//		});
	//	}
	//}

	//sampgdk::SetTimer(1000, true, WorldTimeChanger, 0);

	DB::CDataBase::get().Init();

	CVehicleFactory::get().Create(487, 0, 0, 4.0f, 0, 0, 0);
	return false;
});