#include "stdafx.h"

Event::CPlayerCommand help("/help", [](CPlayer* player) -> bool {
	player->ShowChoiceDialog("{00AA00}������ �� ��������", "LOL", "�������");

	return true;
});