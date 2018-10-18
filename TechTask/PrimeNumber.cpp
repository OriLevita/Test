#include "PrimeNumber.h"
#include <memory>
#include <future>

bool PrimeNumber::IsPrime(int n)
{
	if (n <= 1)
		return  false;

	for (auto i = 2; i * i <= n; i++)
	{
		if ((n % i) == 0)
			return  false;
	}
	return true;
}

PrimeNumbersPtr PrimeNumber::SaveNumbers(unsigned int low, unsigned  int high)
{
	PrimeNumbersPtr vectorValues(new std::vector<int>);
	if (low >= high)
	{
		std::cout << "Error parametrs func SaveNumbers, low >= high." << std::endl;
		return vectorValues;
	}
	for (auto i = low; i <= high; i++)
	{
		if (IsPrime(i) == false)
		{
			continue;
		}
		vectorValues->push_back(i);
	}
	return vectorValues;
}

void PrimeNumber::FillVector(std::vector<int> &vectorValues)
{
	if (GetVectorIntervals().size() < 1)
	{
		std::cout << "no intervals." << std::endl;
		exit(-1);
	}

	std::vector<std::future<PrimeNumbersPtr>> results;
	for (const auto & interval : this->GetVectorIntervals())
	{
		results.push_back(std::async(std::launch::async, [=](int low, int high) -> PrimeNumbersPtr
		{
			return SaveNumbers(low, high);
		}, interval.low, interval.high));
	};

	for (auto &future : results)
	{
		PrimeNumbersPtr tmp = future.get();
		vectorValues.insert(vectorValues.end(), tmp->begin(), tmp->end());
	}
}