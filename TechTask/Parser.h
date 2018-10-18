#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "PrimeNumber.h"

class Parser
{
	std::string buff;
	bool isCorrectHeader(const std::string & text);
	bool isCorrectCloseHeader(const std::string & text);
	bool isCorrectNodeIntervals(const std::string & text);
	bool isCorrectCloseNodeIntervals(const std::string & text);
	bool isCorrectNodeInterval(const std::string & text);
	bool isCorrectCloseNodeInterval(const std::string & text);
public:
	Parser() {};

	// —читать интервалы из файла и заполнить ими вектор.
	void CheckFile(std::string filename, std::vector<Interval> &vectorIntervals);

	// ”далить лишние символы из слова
	void Trim(std::string& text);

	void PushInterval(std::ifstream &file, std::string &s, std::vector<Interval> &vectorIntervals);

	void ReadAndFormatStr(std::ifstream &file, std::string &str);
};

