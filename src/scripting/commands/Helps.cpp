#include "stdafx.h"

Event::CPlayerCommand help("/help", [](CPlayer* player) -> bool {
	player->ShowChoiceDialog("{00AA00}Помощь по командам", "LOL", "Понятно");

	return true;
});