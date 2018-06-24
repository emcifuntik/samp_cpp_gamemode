#pragma once

namespace DB {
	class CDataBase : public CSingleton<CDataBase>
	{
		friend class CSingleton<CDataBase>;

		sqlite3 * dbFile = nullptr;
		const char* dbName = "database.sqlite";
		const char* playersInitialQuery =
			R"sql(
CREATE TABLE IF NOT EXISTS users (
	user_id INTEGER PRIMARY KEY AUTOINCREMENT,
	user_name CHAR(24) NOT NULL,
	user_password INTEGER NOT NULL,
	user_position_x REAL NOT NULL DEFAULT 0,
	user_position_y REAL NOT NULL DEFAULT 0,
	user_position_z REAL NOT NULL DEFAULT 0,
	user_heading REAL NOT NULL DEFAULT 0);
CREATE TABLE IF NOT EXISTS vehicles (
	vehicle_id INTEGER PRIMARY KEY AUTOINCREMENT,
	vehicle_model INTEGER NOT NULL,
	vehicle_owner INTEGER NOT NULL,
	vehicle_position_x REAL NOT NULL DEFAULT 0,
	vehicle_position_y REAL NOT NULL DEFAULT 0,
	vehicle_position_z REAL NOT NULL DEFAULT 0,
	vehicle_heading REAL NOT NULL DEFAULT 0,
	vehicle_insurance INTEGER NOT NULL DEFAULT 0,
	vehicle_health REAL NOT NULL DEFAULT 1000,
	vehicle_fuel REAL NOT NULL DEFAULT 0,
	vehicle_color1 INTEGER NOT NULL DEFAULT 0,
	vehicle_color2 INTEGER NOT NULL DEFAULT 0,
	vehicle_paintjob INTEGER NOT NULL DEFAULT 0,
	vehicle_mod_spoiler INTEGER NOT NULL DEFAULT 0,
	vehicle_mod_hood INTEGER NOT NULL DEFAULT 0,
	vehicle_mod_roof INTEGER NOT NULL DEFAULT 0,
	vehicle_mod_sideskirt INTEGER NOT NULL DEFAULT 0,
	vehicle_mod_lamps INTEGER NOT NULL DEFAULT 0,
	vehicle_mod_nitro INTEGER NOT NULL DEFAULT 0,
	vehicle_mod_exhaust INTEGER NOT NULL DEFAULT 0,
	vehicle_mod_wheels INTEGER NOT NULL DEFAULT 0,
	vehicle_mod_stereo INTEGER NOT NULL DEFAULT 0,
	vehicle_mod_hydraulics INTEGER NOT NULL DEFAULT 0,
	vehicle_mod_front_bumper INTEGER NOT NULL DEFAULT 0,
	vehicle_mod_rear_bumper INTEGER NOT NULL DEFAULT 0,
	vehicle_mod_vent_right INTEGER NOT NULL DEFAULT 0,
	vehicle_mod_vent_left INTEGER NOT NULL DEFAULT 0,
	vehicle_dmg_panels INTEGER NOT NULL DEFAULT 0,
	vehicle_dmg_doors INTEGER NOT NULL DEFAULT 0,
	vehicle_dmg_lights INTEGER NOT NULL DEFAULT 0,
	vehicle_dmg_tires INTEGER NOT NULL DEFAULT 0,
	vehicle_param_engine INTEGER NOT NULL DEFAULT 0,
	vehicle_param_lights INTEGER NOT NULL DEFAULT 0,
	vehicle_param_alarm INTEGER NOT NULL DEFAULT 0,
	vehicle_param_doors INTEGER NOT NULL DEFAULT 0,
	vehicle_param_bonnet INTEGER NOT NULL DEFAULT 0,
	vehicle_param_boot INTEGER NOT NULL DEFAULT 0,
	FOREIGN KEY(vehicle_owner) REFERENCES users(user_id));
)sql";
		//DROP TABLE IF EXISTS users;
		~CDataBase();
	public:
		void Init();

		CPreparedStatement* CreateStatement(std::string query);
		bool Query(const std::string& query, std::string& errorText);
		sqlite_int64 LastInsertID();

		/*bool UserRegistered(const char *username);
		bool RegisterUser(const char * username, const char * password);
		bool LoginUser(CPlayer * player, const char * username, const char * password);
		bool SaveUser(CPlayer * player);*/
	};
}


