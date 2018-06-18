#include "stdafx.h"

Game::CLoaderIPL::CLoaderIPL(const std::string & filename)
{
	file = new std::ifstream(filename, std::ifstream::in);
}

Game::CLoaderIPL::~CLoaderIPL()
{
	file->close();
	delete[] file;
}

void Game::CLoaderIPL::Load()
{
	while (file->good()) {
		char line[1024];
		file->getline(line, 1024);
		HandleLine(line);
	}
}

void Game::CLoaderIPL::HandleLine(const std::string & line)
{
	if (line.size() == 0)
		return;

	if (line.at(0) == '#') //Ignore comments
		return;
	
	if (currentSector == IPLSector::None)
		return HandleIPLSectorSelect(line);

	if (HandleIPLSectorEnd(line))
		return;

	HandleIPLData(line);
}

void Game::CLoaderIPL::HandleIPLSectorSelect(const std::string & line)
{
	std::string upperLine = line;
	std::transform(upperLine.begin(), upperLine.end(), upperLine.begin(), ::toupper);

	if (upperLine == "INST")
		currentSector = IPLSector::Instance;
	else if (upperLine == "CULL")
		currentSector = IPLSector::Cullzone;
	else if (upperLine == "PATH")
		currentSector = IPLSector::Path;
	else if (upperLine == "GRGE")
		currentSector = IPLSector::Garage;
	else if (upperLine == "ENEX")
		currentSector = IPLSector::EnterExit;
	else if (upperLine == "PICK")
		currentSector = IPLSector::Pickup;
	else if (upperLine == "JUMP")
		currentSector = IPLSector::Jump;
	else if (upperLine == "TCYC")
		currentSector = IPLSector::TimeCycle;
	else if (upperLine == "AUZO")
		currentSector = IPLSector::AudioZone;
	else if (upperLine == "MULT")
		currentSector = IPLSector::Mult;
	else if (upperLine == "CARS")
		currentSector = IPLSector::Cars;
	else
		currentSector = IPLSector::None;
}

bool Game::CLoaderIPL::HandleIPLSectorEnd(const std::string & line)
{
	std::string upperLine = line;
	std::transform(upperLine.begin(), upperLine.end(), upperLine.begin(), ::toupper);

	if (upperLine == "END") {
		currentSector = IPLSector::None;
		return true;
	}

	return false;
}

void Game::CLoaderIPL::HandleIPLData(const std::string & line)
{
	switch (currentSector) {
		case IPLSector::EnterExit:
			HandleIPLEnterExit(line);
			break;
		default:
			//Ignore all data
			break;
	}
}

void Game::CLoaderIPL::HandleIPLEnterExit(const std::string & line)
{
	CEnExManager::get().Parse(line);
	
}
