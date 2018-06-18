#pragma once

namespace DB {
	template<typename T>
	class CSecretDataCell : public IDataCell {
		friend class CDataROw;

		T data;
		DataCellConfig _config;

		T& operator()() {
			return data;
		}

		explicit operator T() const {
			return data;
		}
	public:
		CSecretDataCell(const std::string &field, T def, DataCellConfig config = { 0 }) {
			if (std::is_same<T, float>::value) type = DataType::Float;
			else if (std::is_same<T, uint32_t>::value) type = DataType::UInt32;
			else if (std::is_same<T, uint64_t>::value) type = DataType::UInt64;
			else if (std::is_same<T, int32_t>::value) type = DataType::Int32;
			else if (std::is_same<T, int64_t>::value) type = DataType::Int64;
			else if (std::is_same<T, std::string>::value) type = DataType::String;
			else if (std::is_same<T, bool>::value) type = DataType::Boolean;

			fieldName = field;
			data = def;
			_config = config;
		}

		CSecretDataCell& operator=(T value) {
			data = value;
			changed = true;
			return *this;
		}

		const std::string& GetName() {
			return fieldName;
		}

		std::string GetCreateLine() {
			std::stringstream ss;
			ss << fieldName;

			if (std::is_same<T, float>::value) ss << " REAL";
			else if (std::is_same<T, uint32_t>::value ||
				std::is_same<T, uint64_t>::value ||
				std::is_same<T, int32_t>::value ||
				std::is_same<T, int64_t>::value ||
				std::is_same<T, bool>::value) ss << " INTEGER";
			else if (std::is_same<T, std::string>::value) ss << " TEXT";

			if (_config.PrimaryKey)
				ss << " PRIMARY KEY";
			else {
				if (_config.Unique)
					ss << " UNIQUE";
				if (!_config.Null)
					ss << " NOT NULL";
			}
			if (_config.Autoincrement)
				ss << " AUTOINCREMENT";

			if (std::is_same<T, float>::value) ss << " REAL";
			else if (
				std::is_same<T, float>::value ||
				std::is_same<T, uint32_t>::value ||
				std::is_same<T, uint64_t>::value ||
				std::is_same<T, int32_t>::value ||
				std::is_same<T, int64_t>::value ||
				std::is_same<T, bool>::value) ss << " DEFAULT " << data;
			else if (std::is_same<T, std::string>::value) ss << " DEFAULT '" << data << "'";
		}
	};
}
