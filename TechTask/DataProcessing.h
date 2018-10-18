#pragma once
#include "PrimeNumber.h"

class DataProcessing
{
	std::string fileResult;
public:
	DataProcessing(std::string savefile) :fileResult(savefile) {}
	void SaveResult(std::vector<int> const & vectorNumbers);
};

