#pragma once

namespace DB {
	class CPlayerData: public CDataRow {
		CSecretDataCell<std::string> username = CSecretDataCell<std::string>("user_name", "", {false, false, true, false });
		CSecretDataCell<uint32_t> password = CSecretDataCell<uint32_t>("user_password", 0);
	public:
		CDataCell<float> posX = CDataCell<float>("user_position_x", 0.0f);
		CDataCell<float> posY = CDataCell<float>("user_position_y", 0.0f);
		CDataCell<float> posZ = CDataCell<float>("user_position_z", 5.0f);
		CDataCell<float> heading = CDataCell<float>("user_heading", 0.0f);

		CPlayerData():CDataRow("users", "user_id") {
			RegisterSecretCell(username);
			RegisterSecretCell(password);

			RegisterCell(posX);
			RegisterCell(posY);
			RegisterCell(posZ);
			RegisterCell(heading);
		}

		bool Auth(const std::string& name, uint32_t pass) {
			username = name;
			password = pass;
			std::vector<IDataCell*> fields;
			fields.push_back(&username);
			fields.push_back(&password);
			return FindByFields(fields);
		}

		bool Register(const std::string& name, uint32_t pass) {
			username = name;
			password = pass;
			return Insert();
		}

		bool Exists(const std::string& name) {
			CDataCell<std::string> nameField("user_name", name);
			return CDataRow::Exists(nameField);
		}

		//bool 
	};
};
