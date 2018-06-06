#pragma once

template<typename T>
class CDataCell {
	T data;
	bool changed = false;
	std::string fieldName;
public:
	CDataCell(const std::string &field, T def) {
		fieldName = field;
		data = def;
	}

	CDataCell& operator=(T value) {
		data = value;
		changed = true;
		return *this;
	}

	explicit operator T() const { 
		return data;
	}

	const std::string& GetName() {
		return fieldName;
	}
};