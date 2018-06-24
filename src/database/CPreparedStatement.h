#pragma once

namespace DB {
	class CPreparedStatement {
		friend class CDataBase;
		friend class CDataRow;

		sqlite3_stmt *stmt;
		sqlite3* dbHandler;
		uint32_t varIndex = 1;
		uint32_t writeIndex = 0;

		CPreparedStatement(sqlite3 *db, std::string query): dbHandler(db) {
			if (sqlite3_prepare(dbHandler, query.c_str(), query.size(), &stmt, nullptr)) {
				std::string errMessage = sqlite3_errmsg(dbHandler);
				Log::Error << errMessage << std::endl;
				throw std::exception(errMessage.c_str());
			}
		}

		CPreparedStatement& operator<<(const IDataCell* cell) {
			switch (cell->type) {
			case DataType::Float:
				if (sqlite3_bind_double(stmt, varIndex++, (*(CDataCell<float>*)(cell))()))
					throw std::exception(sqlite3_errmsg(dbHandler));
				break;
			case DataType::Int32:
				if (sqlite3_bind_int(stmt, varIndex++, (*(CDataCell<int32_t>*)(cell))()))
					throw std::exception(sqlite3_errmsg(dbHandler));
				break;
			case DataType::UInt32:
				if (sqlite3_bind_int(stmt, varIndex++, (*(CDataCell<uint32_t>*)(cell))()))
					throw std::exception(sqlite3_errmsg(dbHandler));
				break;
			case DataType::Int64:
				if (sqlite3_bind_int64(stmt, varIndex++, (*(CDataCell<int64_t>*)(cell))()))
					throw std::exception(sqlite3_errmsg(dbHandler));
				break;
			case DataType::UInt64:
				if (sqlite3_bind_int64(stmt, varIndex++, (*(CDataCell<uint64_t>*)(cell))()))
					throw std::exception(sqlite3_errmsg(dbHandler));
				break;
			case DataType::String:
				if (sqlite3_bind_text(stmt, varIndex++, (*(CDataCell<std::string>*)(cell))().c_str(), (*(CDataCell<std::string>*)(cell))().size(), nullptr))
					throw std::exception(sqlite3_errmsg(dbHandler));
				break;
			case DataType::Boolean:
				if (sqlite3_bind_int(stmt, varIndex++, (*(CDataCell<bool>*)(cell))()))
					throw std::exception(sqlite3_errmsg(dbHandler));
				break;
			}
			return (*this);
		}

		CPreparedStatement& operator>>(const IDataCell* cell) {
			switch (cell->type) {
			case DataType::Float:
				(*(CDataCell<float>*)(cell)) = static_cast<float>(sqlite3_column_double(stmt, writeIndex++));
				break;
			case DataType::Int32:
				(*(CDataCell<int32_t>*)(cell)) = sqlite3_column_int(stmt, writeIndex++);
				break;
			case DataType::UInt32:
				(*(CDataCell<uint32_t>*)(cell)) = sqlite3_column_int(stmt, writeIndex++);
				break;
			case DataType::Int64:
				(*(CDataCell<int64_t>*)(cell)) = sqlite3_column_int64(stmt, writeIndex++);
				break;
			case DataType::UInt64:
				(*(CDataCell<uint64_t>*)(cell)) = sqlite3_column_int64(stmt, writeIndex++);
				break;
			case DataType::String:
				(*(CDataCell<std::string>*)(cell)) = (const char*)sqlite3_column_text(stmt, writeIndex++);
				break;
			case DataType::Boolean:
				(*(CDataCell<bool>*)(cell)) = sqlite3_column_int(stmt, writeIndex++);
				break;
			}
			return (*this);
		}

		CPreparedStatement& operator>>(uint64_t& cell) { cell = sqlite3_column_int(stmt, writeIndex++);return (*this);}
		CPreparedStatement& operator>>(int64_t& cell) { cell = sqlite3_column_int(stmt, writeIndex++);return (*this);}
		CPreparedStatement& operator>>(uint32_t& cell) { cell = sqlite3_column_int(stmt, writeIndex++);return (*this);}
		CPreparedStatement& operator>>(int32_t& cell) { cell = sqlite3_column_int(stmt, writeIndex++);return (*this);}
		CPreparedStatement& operator>>(bool& cell) {cell = sqlite3_column_int(stmt, writeIndex++);return (*this);}

		std::string Error() {
			return sqlite3_errmsg(dbHandler);
		}

		int Step() {
			return sqlite3_step(stmt);
		}

		int Finalize() {
			return sqlite3_finalize(stmt);
		}
	};
};