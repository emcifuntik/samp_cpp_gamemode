#pragma once


namespace DB {
	typedef struct dcConfig {
		bool PrimaryKey : 1;
		bool Autoincrement : 1;
		bool Unique : 1;
		bool Null : 1;
	} DataCellConfig;

	typedef enum tagDataType {
		Unknown,
		Int32,
		UInt32,
		Int64,
		UInt64,
		Float,
		String,
		Boolean
	} DataType;

	class IDataCell {
		friend class CDataRow;
		friend class CPreparedStatement;
	protected:
		DataType type = DataType::Unknown;
		bool changed = false;
		std::string fieldName;
	public:
		static const DataCellConfig& Config() {
			static const DataCellConfig DefaultConfig = { false };
			return DefaultConfig;
		}

		std::string Create();
	};
}
