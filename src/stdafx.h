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
#include <map>

//Patterns
#include "patterns\CSingleton.h"

//Utils
#include "utils\Utils.h"

//Internal
#include "internal\sampgdk\sampgdk.h"
#include "internal\plugin.h"
#include "internal\logging\Log.h"

//Entities
#include "entities\CPlayer.h"
#include "entities\CVehicle.h"

//Managers
#include "managers\CPlayerManager.h"
#include "managers\CGameManager.h"
#include "managers\CTimerManager.h"

//Command processor
#include "core\CCommandProcessor.h"

//Database
#include "database\sqlite\sqlite3.h"
#include "database\CDataBase.h"

//Events
#include "events\CBaseEvent.h"
#include "events\player\CPlayerConnect.h"
#include "events\player\CPlayerDisconnect.h"
#include "events\player\CPlayerSpawn.h"
#include "events\player\CPlayerCommand.h"
#include "events\game\CGameInited.h"

