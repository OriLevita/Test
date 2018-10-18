#pragma once
#include "PrimeNumber.h"
#include <fstream>
#include <future>

class DataProcessing
{
	std::string fileResult;
public:
	DataProcessing(std::string savefile) :fileResult(savefile) {}
	void SaveResult(std::vector<int> & vectorNumbers);
};

