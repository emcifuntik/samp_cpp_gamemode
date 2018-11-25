#pragma once

namespace DB {
	class CDataBase : public CSingleton<CDataBase>
	{
		friend class CSingleton<CDataBase>;

		sqlite3 * dbFile = nullptr;
		const char* dbName = "database.sqlite";
		~CDataBase();
	public:
		void Init();

		CPreparedStatement* CreateStatement(std::string query);
		bool Query(const std::string& query, std::string& errorText);
		sqlite_int64 LastInsertID();
	};
}


