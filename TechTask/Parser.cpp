#include "Parser.h"
#include <iostream>
#include <algorithm>

void  Parser::PushInterval(std::ifstream &file, std::string &line, std::vector<Interval> &vectorIntervals)
{
	try {
		ReadAndFormatStr(file, line);

		int lowInterval, highInterval;

		if (line.find("<low>") || !line.find("</low>"))
		{
			std::cout << "Error, invalid tag low";
			exit(1);
		}
		int stringLengthLow = 12;
		if (line.length() < stringLengthLow)
		{
			std::cout << "No parameters found in node, <low>" << std::endl;
			exit(-1);
		}
		std::string tempString;
		for (int i = line.find_first_not_of("<low>"); i != line.rfind("</low>"); i++)
		{
			tempString += line[i];
		}

		lowInterval = std::stoi(tempString);
		tempString.erase();

		ReadAndFormatStr(file, line);
		if (line.find("<high>") || !line.find("</high>"))
		{
			std::cout << "Error, invalid tag high";
			exit(1);
		}
		int stringLengthHigh = 14;
		if (line.length() < stringLengthHigh)
		{
			std::cout << "No parameters found in node, <high>" << std::endl;
			exit(-1);
		}

		for (int i = line.find_first_not_of("<high>"); i != line.rfind("</high>"); i++)
		{
			tempString += line[i];
		}
		highInterval = std::stoi(tempString);
		vectorIntervals.push_back({ lowInterval,highInterval });
	}
	catch (std::invalid_argument)
	{
		std::cout << "Invalid input data. " << std::endl;
		exit(-1);
	}
}

void Parser::ReadAndFormatStr(std::ifstream &file, std::string &line)
{
	std::getline(file, line);
	Trim(line);
}

void Parser::CheckFile(std::string filename, std::vector<Interval> &vectorIntervals)
{
	std::ifstream file(filename);
	if (!file)
	{
		std::cout << "Could not open file for reading..." << std::endl;
		exit(-1);
	}

	std::string line;
	ReadAndFormatStr(file, line);
	if (!isCorrectHeader(line))
	{
		std::cout << "Incorrect header" << std::endl;
		exit(1);
	}

	ReadAndFormatStr(file, line);

	if (!isCorrectNodeIntervals(line))
	{
		std::cout << "Incorrect node Intervals" << std::endl;
		exit(1);
	}

	while (!file.eof())
	{
		ReadAndFormatStr(file, line);
		if (!isCorrectNodeInterval(line))
		{
			std::cout << "Incorrect node Interval" << std::endl;
			break;
		}

		PushInterval(file, line, vectorIntervals);

		ReadAndFormatStr(file, line);
		if (!isCorrectCloseNodeInterval(line))
		{
			std::cout << "Incorrect node /Interval" << std::endl;
			break;
		}
	}

	if (!isCorrectCloseNodeIntervals(line))
	{
		std::cout << "Incorrect node /Intervals" << std::endl;
		exit(1);
	}

	ReadAndFormatStr(file, line);
	if (!isCorrectCloseHeader(line))
	{
		std::cout << "Incorrect /header" << std::endl;
		exit(1);
	}
	file.close();
}

void Parser::Trim(std::string& text)
{
	char chars[] = "\t ";
	int lenchar = sizeof(chars);
	for (unsigned int i = 0; i < lenchar; i++)
	{
		text.erase(std::remove(text.begin(), text.end(), chars[i]), text.end());
	}
}

bool Parser::isCorrectHeader(const std::string & text)
{
	return !text.compare("<root>");
}

bool Parser::isCorrectCloseHeader(const std::string & text)
{
	return !text.compare("</root>");
}

bool Parser::isCorrectNodeIntervals(const std::string & text)
{
	return !text.compare("<intervals>");
}

bool Parser::isCorrectCloseNodeIntervals(const std::string & text)
{
	return !text.compare("</intervals>");
}

bool Parser::isCorrectNodeInterval(const std::string & text)
{
	return !text.compare("<interval>");
}

bool Parser::isCorrectCloseNodeInterval(const std::string & text)
{
	return !text.compare("</interval>");
}
