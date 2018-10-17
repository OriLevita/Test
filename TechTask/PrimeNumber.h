#pragma once
#include <iostream>
#include <vector>
#include <mutex>

class PrimeNumber
{
private:
	int low;
	int high;
	std::mutex mtx;
	std::vector<int> vc;
public:
	PrimeNumber() : low(0), high(0) { this->vc.reserve(10); };

	std::vector<int> GetVec() { return vc; }
	// ≈сли число простое возвращает true
	bool IsPrime(int n);
	//«аписывает простые числа из интервала в вектор
	void SaveNumbers(unsigned int LOW, unsigned  int HIGH);
	~PrimeNumber() {};
};

