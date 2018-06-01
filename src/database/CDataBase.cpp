#include "stdafx.h"

CDataBase::~CDataBase()
{
	sqlite3_close(dbFile);
}

void CDataBase::Init()
{
	char *err = 0;
	if (sqlite3_open(dbName, &dbFile)) {
		Log::Error << "[SQLite] Ошибка открытия/создания БД: " << sqlite3_errmsg(dbFile) << Log::Endl;
	}
	else {
		Log::Debug << "[SQLite] База данных загружена из \"" << dbName << "\"" << Log::Endl;
		if (!sqlite3_exec(dbFile, playersInitialQuery, 0, 0, &err)) {
			Log::Debug << "[SQLite] База данных инициализирована" << Log::Endl;
		}
		else {
			Log::Error << "[SQLite] Ошибка инициализации БД: " << sqlite3_errmsg(dbFile) << Log::Endl;
		}
	}
}

bool CDataBase::UserRegistered(const char * username)
{
	bool exists = false;
	sqlite3_stmt *stmt;
	const char* sql = "SELECT COUNT(user_id) as `exists` FROM users WHERE user_name = ?";
	sqlite3_prepare(dbFile, sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, username, strlen(username), nullptr);

	int result;
	do
	{
		result = sqlite3_step(stmt);
		switch (result)
		{
		case SQLITE_DONE:
			break;
		case SQLITE_ROW:
		{
			exists = sqlite3_column_int(stmt, 0) > 0;
			Log::Debug << "[SQLite] Exists = " << (exists ? "true" : "false") <<  Log::Endl;
		}
		break;
		default:
			Log::Error << "[SQLite] Неизвестный результат: " << result << Log::Endl;
			break;
		}
	} while (result == SQLITE_ROW);
	sqlite3_finalize(stmt);
	return exists;
}

bool CDataBase::RegisterUser(const char * username, const char * password)
{
	int passHash = jhash(password);
	sqlite3_stmt *stmt;
	const char* sql = "INSERT INTO users (user_name, user_password) VALUES (?, ?)";
	if (sqlite3_prepare(dbFile, sql, strlen(sql), &stmt, nullptr)) {
		Log::Error << "[SQLite] Ошибка регистрации игрока: " << sqlite3_errmsg(dbFile) << Log::Endl;
	}
	if (sqlite3_bind_text(stmt, 1, username, strlen(username), nullptr)) {
		Log::Error << "[SQLite] Ошибка регистрации игрока: " << sqlite3_errmsg(dbFile) << Log::Endl;
	}
	if (sqlite3_bind_int(stmt, 2, passHash)) {
		Log::Error << "[SQLite] Ошибка регистрации игрока: " << sqlite3_errmsg(dbFile) << Log::Endl;
	}

	int result;
	do
	{
		result = sqlite3_step(stmt);
		switch (result)
		{
		case SQLITE_DONE:
			break;
		case SQLITE_ERROR:
			Log::Error << "[SQLite] Ошибка регистрации игрока: " << sqlite3_errmsg(dbFile) << Log::Endl;
			break;
		default:
			Log::Error << "[SQLite] Неизвестный результат: " << result << Log::Endl;
			break;
		}
	} while (result == SQLITE_ROW);
	sqlite3_finalize(stmt);
	return true;
}

bool CDataBase::LoginUser(CPlayer* player, const char * username, const char * password)
{
	int passHash = jhash(password);
	sqlite3_stmt *stmt;
	const char* sql = "SELECT user_id, user_position_x, user_position_y, user_position_z, user_heading FROM users WHERE user_name = ? AND user_password = ?";
	if (sqlite3_prepare(dbFile, sql, strlen(sql), &stmt, nullptr)) {
		Log::Error << "[SQLite] Ошибка авторизации игрока: " << sqlite3_errmsg(dbFile) << Log::Endl;
	}
	if (sqlite3_bind_text(stmt, 1, username, strlen(username), nullptr)) {
		Log::Error << "[SQLite] Ошибка авторизации игрока: " << sqlite3_errmsg(dbFile) << Log::Endl;
	}
	if (sqlite3_bind_int(stmt, 2, passHash)) {
		Log::Error << "[SQLite] Ошибка авторизации игрока: " << sqlite3_errmsg(dbFile) << Log::Endl;
	}

	bool found = false;
	int result;
	do
	{
		result = sqlite3_step(stmt);
		switch (result)
		{
		case SQLITE_DONE:
			break;
		case SQLITE_ROW:
		{
			player->sqlID = sqlite3_column_int(stmt, 0);
			player->lastPosition.x = sqlite3_column_float(stmt, 1);
			player->lastPosition.y = sqlite3_column_float(stmt, 2);
			player->lastPosition.z = sqlite3_column_float(stmt, 3);
			player->heading = sqlite3_column_float(stmt, 4);
			found = true;
			break;
		}
		case SQLITE_ERROR:
			Log::Error << "[SQLite] Ошибка авторизации игрока: " << sqlite3_errmsg(dbFile) << Log::Endl;
			break;
		default:
			Log::Error << "[SQLite] Неизвестный результат: " << result << Log::Endl;
			break;
		}
	} while (result == SQLITE_ROW);
	sqlite3_finalize(stmt);
	return found;
}

bool CDataBase::SaveUser(CPlayer* player)
{
	sqlite3_stmt *stmt;
	const char* sql = "UPDATE users SET user_position_x = ?, user_position_y = ?, user_position_z = ?, user_heading = ? WHERE user_id = ?";
	if (sqlite3_prepare(dbFile, sql, strlen(sql), &stmt, nullptr)) {
		Log::Error << "[SQLite] Ошибка авторизации игрока: " << sqlite3_errmsg(dbFile) << Log::Endl;
	}
	int n = 1;
	if (sqlite3_bind_double(stmt, n++, player->lastPosition.x)) {
		Log::Error << "[SQLite] Ошибка авторизации игрока: " << sqlite3_errmsg(dbFile) << Log::Endl;
	}
	if (sqlite3_bind_double(stmt, n++, player->lastPosition.y)) {
		Log::Error << "[SQLite] Ошибка авторизации игрока: " << sqlite3_errmsg(dbFile) << Log::Endl;
	}
	if (sqlite3_bind_double(stmt, n++, player->lastPosition.z)) {
		Log::Error << "[SQLite] Ошибка авторизации игрока: " << sqlite3_errmsg(dbFile) << Log::Endl;
	}
	if (sqlite3_bind_double(stmt, n++, player->heading)) {
		Log::Error << "[SQLite] Ошибка авторизации игрока: " << sqlite3_errmsg(dbFile) << Log::Endl;
	}
	if (sqlite3_bind_int(stmt, n++, player->sqlID)) {
		Log::Error << "[SQLite] Ошибка авторизации игрока: " << sqlite3_errmsg(dbFile) << Log::Endl;
	}

	bool found;
	int result;
	do
	{
		result = sqlite3_step(stmt);
		switch (result)
		{
		case SQLITE_DONE:
			break;
		case SQLITE_ERROR:
			Log::Error << "[SQLite] Ошибка авторизации игрока: " << sqlite3_errmsg(dbFile) << Log::Endl;
			break;
		default:
			Log::Error << "[SQLite] Неизвестный результат: " << result << Log::Endl;
			break;
		}
	} while (result == SQLITE_ROW);
	sqlite3_finalize(stmt);
	return true;
}
