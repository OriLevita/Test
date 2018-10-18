#pragma once
#include <iostream>
#include <vector>
#include <future>
#include <mutex>

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
	std::vector<int> SaveNumbers(unsigned int LOW, unsigned  int HIGH, std::vector<int> &vectorValues);

	~PrimeNumber() {};
};

