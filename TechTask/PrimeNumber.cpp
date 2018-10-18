#include "PrimeNumber.h"

// Если число простое возвращает true
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

// Записывает простые числа в вектор
std::vector<int> PrimeNumber::SaveNumbers(unsigned int LOW, unsigned  int HIGH, std::vector<int> vectorValues)
{
	if (LOW >= HIGH)
	{
		std::cout << "Error parametrs func SaveNumbers, LOW >= HIGH." << std::endl;
		return vectorValues;
	}
	for (auto i = LOW; i <= HIGH; i++)
	{
		if (IsPrime(i) == false) continue;
		std::cout << i << std::endl;
		vectorValues.push_back(i);
	}
	return vectorValues;
}

//Изъять из вектора интервалы
void PrimeNumber::FillVector(std::vector<int> &vectorValues)
{
	std::vector<std::future<std::vector<int>>> results;

	if (GetVectorIntervals().size() < 1)
	{
		std::cout << "no intervals." << std::endl;
		exit(-1);
	}

	for (const auto & interval : this->GetVectorIntervals())
	{
		results.push_back(std::async(std::launch::async, [&](int low, int high) -> std::vector<int>
		{
			return SaveNumbers(low, high, vectorValues);
		}, interval.low, interval.high));
	};


}