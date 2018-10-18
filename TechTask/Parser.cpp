#include "Parser.h"

void  Parser::PushInterval(std::ifstream &file, std::string &str, std::vector<Interval> &vectorIntervals)
{
	try {
		ReadAndFormatStr(file, str);
		std::string tmp;
		int low, high;

		if (str.find("<low>") || !str.find("</low>"))
		{
			std::cout << "Error, invalid tag low";
			exit(1);
		}

		if (str.length() < 12)
		{
			std::cout << "No parameters found in node, <low>" << std::endl;
			exit(-1);
		}
		for (int i = str.find_first_not_of("<low>"); i != str.rfind("</low>"); i++)
		{
			tmp += str[i];
		}

		low = std::stoi(tmp);
		tmp.erase();

		ReadAndFormatStr(file, str);
		if (str.find("<high>") || !str.find("</high>"))
		{
			std::cout << "Error, invalid tag high";
			exit(1);
		}

		if (str.length() < 14)
		{
			std::cout << "No parameters found in node, <high>" << std::endl;
			exit(-1);
		}

		for (int i = str.find_first_not_of("<high>"); i != str.rfind("</high>"); i++)
		{
			tmp += str[i];
		}
		high = std::stoi(tmp);
		vectorIntervals.push_back({ low,high });
	}
	catch (std::invalid_argument)
	{
		std::cout << "Invalid input data. " << std::endl;
		exit(-1);
	}
}

//Считать и форматировать строку
void Parser::ReadAndFormatStr(std::ifstream &file, std::string &str)
{
	std::getline(file, str);
	Trim(str);
}

// Прочитать данные из файла и удалить лишние символы
void Parser::CheckFile(std::string filename, std::vector<Interval> &vectorIntervals)
{
	std::ifstream file(filename);
	if (!file)
	{
		std::cout << "Open fRead Error..." << std::endl;
		exit(-1);
	}
	std::string str;

	ReadAndFormatStr(file, str);
	if (isCorrectHeader(str))
	{
		std::cout << "Incorrect header" << std::endl;
		exit(1);
	}

	ReadAndFormatStr(file, str);
	if (isCorrectNodeIntervals(str))
	{
		std::cout << "Incorrect node Intervals" << std::endl;
		exit(1);
	}

	while (!file.eof())
	{
		ReadAndFormatStr(file, str);
		if (isCorrectNodeInterval(str))
		{
			std::cout << "Incorrect node Interval" << std::endl;
			break;
		}

		PushInterval(file, str, vectorIntervals);

		ReadAndFormatStr(file, str);
		if (isCorrectCloseNodeInterval(str))
		{
			std::cout << "Incorrect node /Interval" << std::endl;
			break;
		}

	}

	if (isCorrectCloseNodeIntervals(str))
	{
		std::cout << "Incorrect node /Intervals" << std::endl;
		exit(1);
	}

	ReadAndFormatStr(file, str);
	if (isCorrectCloseHeader(str))
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
	return text.compare("<root>");
}

bool Parser::isCorrectCloseHeader(const std::string & text)
{
	return text.compare("</root>");
}

bool Parser::isCorrectNodeIntervals(const std::string & text)
{
	return text.compare("<intervals>");
}

bool Parser::isCorrectCloseNodeIntervals(const std::string & text)
{
	return text.compare("</intervals>");
}

bool Parser::isCorrectNodeInterval(const std::string & text)
{
	return text.compare("<interval>");
}

bool Parser::isCorrectCloseNodeInterval(const std::string & text)
{
	return text.compare("</interval>");
}
