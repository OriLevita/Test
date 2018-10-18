#pragma once
#include <iostream>
#include <vector>

using PrimeNumbersPtr = std::shared_ptr<std::vector<int>>;

struct Interval
{
	int low;
	int high;
};

class PrimeNumber
{
private:
	std::vector<Interval> vectorIntervals;
public:

	PrimeNumber() { this->vectorIntervals.reserve(10); };

	void FillVector(std::vector<int> &vectorIntervals);

	std::vector<Interval> & GetVectorIntervals() { return vectorIntervals; }
	// ���� ����� ������� ���������� true
	bool IsPrime(int n);
	//���������� ������� ����� �� ��������� � ������
	PrimeNumbersPtr SaveNumbers(unsigned int low, unsigned  int high);

	~PrimeNumber() {};
};

