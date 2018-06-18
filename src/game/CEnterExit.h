#pragma once

namespace Game {
	class CEnterExit {
		friend class CEnExManager;
		CEnterExit(const std::string& line);
		~CEnterExit();

		CVector3f enterPosition;
		float enterRotationRad;
		float enterRadius;
		float exitRadius;
		float unknown;
		CVector3f exitPosition;
		float exitRotation;
		uint8_t interior;
		uint16_t markerFlags;
		std::string interiorName;
		uint8_t skyFlags;
		uint8_t weatherFlags;
		uint8_t timeOn;
		uint8_t timeOff;
	public:
		CVector3f GetEnterPos() { return enterPosition; }
		float GetEnterRotation() { return enterRotationRad; }
		CVector3f GetExitPos() { return exitPosition; }
		float GetExitRotation() { return exitRotation; }
		int GetInterior() { return interior; }
		const std::string& GetName() { return interiorName; }
	};
}