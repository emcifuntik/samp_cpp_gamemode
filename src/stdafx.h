#pragma once
#include <stdio.h>
#include <string>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <codecvt>
#include <vector>
#include <iostream>
#include <functional>
#include <variant>
#include <map>
#include <unordered_map>
#include <sstream>
#include <filesystem>

//Patterns
#include "patterns\CSingleton.h"

//Utils
#include "utils\Utils.h"

//Internal
#include "internal\sampgdk\sampgdk.h"
#include "internal\plugin.h"
#include "internal\logging\Log.h"
#include "internal\colors.h"

//Streamer
#include "vendor\streamer-invoke\streamer.hpp"

//Game
#include "game\CGameDataLoader.h"

//Entities
#include "entities\CPlayer.h"
#include "entities\CVehicle.h"
#include "entities\CObject.h"
#include "entities\CArea.h"
#include "entities\CActor.h"
#include "entities\CPickup.h"

//Managers
#include "managers\CPlayerManager.h"
#include "managers\CGameManager.h"
#include "managers\CTimerManager.h"

//Factories
#include "factories\CVehicleFactory.h"
#include "factories\CObjectFactory.h"
#include "factories\CPickupFactory.h"
#include "factories\CActorFactory.h"

//Command processor
#include "core\CCommandProcessor.h"

//Database
#include "database\sqlite\sqlite3.h"
#include "database\CDataBase.h"
#include "database\CDataCell.h"
#include "database\CPlayerData.h"

//Events
#include "events\CBaseEvent.h"
#include "events\player\CPlayerConnect.h"
#include "events\player\CPlayerDisconnect.h"
#include "events\player\CPlayerSpawn.h"
#include "events\player\CPlayerCommand.h"
#include "events\game\CGameInited.h"

