#include "stdafx.h"

std::string DB::IDataCell::Create()
{
	switch (this->type) {
	case DataType::Float:
		return (*(CDataCell<float>*)(this)).GetCreateLine();
		break;
	case DataType::Int32:
		return (*(CDataCell<int32_t>*)(this)).GetCreateLine();
		break;
	case DataType::UInt32:
		return (*(CDataCell<uint32_t>*)(this)).GetCreateLine();
		break;
	case DataType::Int64:
		return (*(CDataCell<int64_t>*)(this)).GetCreateLine();
		break;
	case DataType::UInt64:
		return (*(CDataCell<uint64_t>*)(this)).GetCreateLine();
		break;
	case DataType::String:
		return (*(CDataCell<std::string>*)(this)).GetCreateLine();
		break;
	case DataType::Boolean:
		return (*(CDataCell<bool>*)(this)).GetCreateLine();
		break;
	default:
		return "";
	}
}
