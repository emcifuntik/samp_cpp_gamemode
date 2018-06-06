#pragma once

class CPlayerData {
	CDataCell<float> posX = CDataCell<float>("user_position_x", 0.0f);
	CDataCell<float> posY = CDataCell<float>("user_position_y", 0.0f);
	CDataCell<float> posZ = CDataCell<float>("user_position_z", 5.0f);
	CDataCell<float> heading = CDataCell<float>("user_heading", 0.0f);

	CPlayerData() {
	}
};

