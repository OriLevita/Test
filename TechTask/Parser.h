#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<algorithm>
#include "PrimeNumber.h"

class Parser
{
	std::string buff;
public:
	Parser() {};

	// ��������� �������������� ����
	void SaveResult(PrimeNumber &obj);

	// ������� ��������� �� ����� � ��������� ��� ������.
	void ReadFile(std::string filename);

	// ������� �� ������� ��������� � ��������� ������
	void FillVector(std::vector<int> vc, std::vector<std::thread> &threads, PrimeNumber &Obj);

	// ������� ������ ������� �� �����
	void Trim(std::string& text);

	void  PushInterval(std::ifstream &file, std::string &s);

	void ReadAndFormatStr(std::ifstream &file, std::string &str);

	bool isCorrectHeader(const std::string & text);
	bool isCorrectCloseHeader(const std::string & text);

	bool isCorrectNodeIntervals(const std::string & text);
	bool isCorrectCloseNodeIntervals(const std::string & text);

	bool isCorrectNodeInterval(const std::string & text);
	bool isCorrectCloseNodeInterval(const std::string & text);

};

