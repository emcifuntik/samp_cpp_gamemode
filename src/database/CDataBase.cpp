#include "stdafx.h"

DB::CDataBase::~CDataBase()
{
	sqlite3_close(dbFile);
}

void DB::CDataBase::Init()
{
	char *err = 0;
	if (sqlite3_open(dbName, &dbFile)) {
		sampgdk::logprintf("[SQLite] Database load error: %s", sqlite3_errmsg(dbFile));
	}
	else {
		sampgdk::logprintf("[SQLite] Database loaded from \"%s\"", dbName);
	}
}

DB::CPreparedStatement * DB::CDataBase::CreateStatement(std::string query)
{
	DB::CPreparedStatement* statement = new DB::CPreparedStatement(dbFile, query);
	return statement;
}

bool DB::CDataBase::Query(const std::string & query, std::string &errorText)
{
	char errMessage[256] = { 0 };
	if (sqlite3_exec(dbFile, query.c_str(), 0, 0, (char**)&errMessage)) {
		errorText = std::string(errMessage);
		return false;
	}
	return true;
}

sqlite_int64 DB::CDataBase::LastInsertID()
{
	return sqlite3_last_insert_rowid(dbFile);
}
