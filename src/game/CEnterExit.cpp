#include "stdafx.h"

Game::CEnterExit::CEnterExit(const std::string& line)
{
	char _interiorName[16] = { 0 };
	setlocale(LC_ALL, "en_US.utf8");
	sscanf_s(line.c_str(), "%f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %d, %d, \"%[A-Z0-9]\", %d, %d, %d, %d",
		&enterPosition.x,
		&enterPosition.y,
		&enterPosition.z,
		&enterRotationRad,
		&enterRadius,
		&exitRadius,
		&unknown,
		&exitPosition.x,
		&exitPosition.y,
		&exitPosition.z,
		&exitRotation,
		&interior,
		&markerFlags,
		_interiorName,
		(unsigned)sizeof(_interiorName),
		&skyFlags,
		&weatherFlags,
		&timeOn,
		&timeOff
	);
	interiorName = _interiorName;
}

Game::CEnterExit::~CEnterExit()
{
}
