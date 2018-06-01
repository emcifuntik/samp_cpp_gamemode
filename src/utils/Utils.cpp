#include "stdafx.h"

void GetInGameTime(int& hours, int& minutes) {
	int currGameTime = time(NULL) % 3600;
	hours = currGameTime / 150;
	minutes = int((currGameTime % 150) / 2.5f);
}

uint32_t jhash(const std::string &key)
{
	uint32_t hash, i;
	for (hash = i = 0; i < key.size(); ++i)
	{
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash;
}