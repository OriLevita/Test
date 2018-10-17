#include "PrimeNumber.h"



// Если число простое возвращает true
bool PrimeNumber::IsPrime(int n)
{
	if (n <= 1) return  false;
	for (auto i = 2; i * i <= n; i++) {
		if ((n % i) == 0)
			return  false;
	}
	return true;
}
// Записывает простые числа в вектор
void PrimeNumber::SaveNumbers(unsigned int LOW, unsigned  int HIGH)
{
	if (LOW >= HIGH)
	{
		std::cout << "Error parametrs func SaveNumbers, LOW >= HIGH." << std::endl;
		return;
	}
	for (auto i = LOW; i <= HIGH; i++)
	{
		if (IsPrime(i) == false) continue;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << i << std::endl;
		this->vc.push_back(i);
	}
}