#pragma once

#define INVALID_FIELD_NAME "INVALID_FIELD_NAME"

namespace DB {
	class CDataRow {
		CDataCell<uint32_t> ID = CDataCell<uint32_t>(INVALID_FIELD_NAME, 0);
		std::string tName;
		std::vector<IDataCell *> _allFields;
		std::vector<IDataCell *> _secretFields;
	protected:
		CDataRow(const char* tableName, const char* idField): tName(tableName) {
			ID = CDataCell<uint32_t>(idField, 0, { true, true, false, false });
		}

		bool RegisterCell(IDataCell& cell) {
			_allFields.push_back(&cell);
			return true;
		}

		bool RegisterSecretCell(IDataCell& cell) {
			_secretFields.push_back(&cell);
			return true;
		}
	public:
		bool CreateTable() {
			std::stringstream ss;
			ss << "CREATE TABLE IF NOT EXISTS " << tName << "(";

			ss << ID.GetCreateLine();
			for (auto cell : _secretFields)
				ss << "," << cell->Create();
			for (auto cell : _allFields)
				ss << "," << cell->Create();
			ss << ");";

			std::string errMessage;
			if (!DB::CDataBase::get().Query(ss.str(), errMessage)) {
				Log::Error << "[SQLite] Ошибка создания таблицы " << tName << ". " << errMessage << std::endl;
				return false;
			}
			return true;
		}

		bool DropTable() {
			std::stringstream ss;
			ss << "DROP TABLE IF EXISTS " << tName << ";";

			std::string errMessage;
			if (!DB::CDataBase::get().Query(ss.str(), errMessage)) {
				Log::Error << "[SQLite] Ошибка удаления таблицы " << tName << ". " << errMessage << std::endl;
				return false;
			}
			return true;
		}

		bool Save() {
			std::vector<IDataCell*> toSave;
			for (auto cell : _allFields)
				if (cell->changed)
					toSave.push_back(cell);

			std::stringstream queryStream;
			queryStream << "UPDATE " << tName << " SET ";
			bool first = true;
			for (auto cell : toSave) {
				if (first) first = false;
				else queryStream << ", ";
				queryStream << cell->fieldName << " = ?";
			}
			queryStream << " WHERE " << ID.fieldName << " = ?";
			auto stmt = CDataBase::get().CreateStatement(queryStream.str());

			for (auto cell : toSave) {
				(*stmt) << cell;
				cell->changed = false;
			}

			(*stmt) << &ID;

			bool saved = false;
			int result;
			do
			{
				result = stmt->Step();
				switch (result)
				{
				case SQLITE_DONE:
					saved = true;
					break;
				case SQLITE_ERROR:
					Log::Error << "[SQLite] Ошибка авторизации игрока: " << stmt->Error() << Log::Endl;
					break;
				default:
					Log::Error << "[SQLite] Неизвестный результат: " << result << Log::Endl;
					break;
				}
			} while (result == SQLITE_ROW);
			stmt->Finalize();
			return saved;
		}

		bool FindByFields(const std::vector<IDataCell*>& cells) {
   			std::stringstream queryStream;
			queryStream << "SELECT " << ID.fieldName;
			for (auto cell : _allFields)
				queryStream << ", " << cell->fieldName;
			queryStream << " FROM " << tName << "WHERE ";
			bool first = true;
			for (auto cell : cells) {
				if (first) first = false;
				else queryStream << " AND ";
				queryStream << cell->fieldName << " = ?";
			}
			queryStream << " LIMIT 1";

			auto stmt = CDataBase::get().CreateStatement(queryStream.str());

			for (auto cell : cells) {
				(*stmt) << cell;
			}

			bool found = false;
			int result;
			do
			{
				result = stmt->Step();
				switch (result)
				{
				case SQLITE_DONE:
					break;
				case SQLITE_ROW:
				{
					(*stmt) >> &ID;
					for (auto cell : _allFields)
						(*stmt) >> cell;
					found = true;
					break;
				}
				case SQLITE_ERROR:
					Log::Error << "[SQLite] Ошибка SELECT запроса: " << stmt->Error() << Log::Endl;
					break;
				default:
					Log::Error << "[SQLite] Неизвестный результат: " << result << Log::Endl;
					break;
				}
			} while (result == SQLITE_ROW);
			stmt->Finalize();
			return found;
		}
	};
}
