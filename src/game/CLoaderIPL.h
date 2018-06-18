#pragma once

namespace Game {
	typedef enum tagIPLSector {
		None,
		Instance,
		Cullzone,
		Path,
		Garage,
		EnterExit,
		Pickup,
		Jump, 
		TimeCycle,
		AudioZone,
		Mult, 
		Cars
	} IPLSector;

	class CLoaderIPL {
		std::ifstream *file = nullptr;
		IPLSector currentSector = IPLSector::None;

		void HandleLine(const std::string& line);
		void HandleIPLSectorSelect(const std::string& line);
		bool HandleIPLSectorEnd(const std::string& line);
		void HandleIPLData(const std::string& line);

		void HandleIPLEnterExit(const std::string& line);
	public:
		CLoaderIPL(const std::string& filename);
		~CLoaderIPL();

		void Load();
	};
}