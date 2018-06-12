#include "stdafx.h"
namespace Houses {
	typedef struct tagHouseInfo {
		float enterX;
		float enterY;
		float enterZ;
		float interiorX;
		float interiorY;
		float interiorZ;
		uint8_t interiorID;
	} HouseInfo;


	Event::CPlayerConnect connect([](CPlayer* player) -> bool {
		player->RemoveBuilding(3824, -2621.4063f, 174.4453f, 6.6094f, 1.0f);
		return false;
	});

	Event::CGameInited init([]() -> bool {
		CObjectFactory::get().Create(19489, -2621.41, 174.45, 6.61, 0.00, 0.00, 90.00);
		CObjectFactory::get().Create(19490, -2621.41, 174.45, 6.61, 0.00, 0.00, 90.00);
		return false;
	});
}
