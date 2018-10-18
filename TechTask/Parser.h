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

	// ������� ��������� �� ����� � ��������� ��� ������.
	void CheckFile(std::string filename,std::vector<Interval> &vecInterval);

	// ������� ������ ������� �� �����
	void Trim(std::string& text);

	void PushInterval(std::ifstream &file, std::string &s, std::vector<Interval> &vecInterval);

	void ReadAndFormatStr(std::ifstream &file, std::string &str);

	bool isCorrectHeader(const std::string & text);
	bool isCorrectCloseHeader(const std::string & text);

	bool isCorrectNodeIntervals(const std::string & text);
	bool isCorrectCloseNodeIntervals(const std::string & text);

	bool isCorrectNodeInterval(const std::string & text);
	bool isCorrectCloseNodeInterval(const std::string & text);

};

