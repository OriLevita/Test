#include "Parser.h"

void  Parser::PushInterval(std::ifstream &file, std::string &str)
{
	try {
		ReadAndFormatStr(file, str);
		std::string tmp;
		int low, high;

		if (str.find("<low>") || !str.find("</low>"))
		{
			std::cout << "Error, invalid tag low";
			return;
		}
		std::cout << str.length() << std::endl;
		if (str.length() < 12)
		{
			throw - 1;
		}
		for (int i = str.find_first_not_of("<low>"); i != str.rfind("</low>"); i++)
		{
			tmp += str[i];
		}

		if (std::stoi(tmp))
		{
			low = std::stoi(tmp);
		}
		tmp.erase();

		ReadAndFormatStr(file, str);
		if (str.find("<high>") || !str.find("</high>"))
		{
			std::cout << "Error, invalid tag high";
			return;
		}

		if (str.length() < 14)
		{
			throw - 1;
		}

		for (int i = str.find_first_not_of("<high>"); i != str.rfind("</high>"); i++)
		{
			tmp += str[i];
		}
		high = std::stoi(tmp);
	}
	catch (int)
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
void Parser::ReadFile(std::string filename)
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
		return;
	}

	ReadAndFormatStr(file, str);
	if (isCorrectNodeIntervals(str))
	{
		std::cout << "Incorrect node Intervals" << std::endl;
		return;
	}

	while (!file.eof())
	{
		ReadAndFormatStr(file, str);
		if (isCorrectNodeInterval(str))
		{
			std::cout << "Incorrect node Interval" << std::endl;
			return;
		}

		PushInterval(file, str);

		ReadAndFormatStr(file, str);
		if (isCorrectCloseNodeInterval(str))
		{
			std::cout << "Incorrect node /Interval" << std::endl;
			return;
		}

	}

	ReadAndFormatStr(file, str);
	if (isCorrectNodeIntervals(str))
	{
		std::cout << "Incorrect node /Intervals" << std::endl;
		return;
	}

	ReadAndFormatStr(file, str);
	if (isCorrectCloseHeader(str))
	{
		std::cout << "Incorrect /header" << std::endl;
		return;
	}
	file.close();
}

// Изъять из вектора интервалы
void Parser::FillVector(std::vector<int> vc, std::vector<std::thread> &threads, PrimeNumber &Obj)
{
	if (vc.size() < 2)
	{
		std::cout << "no intervals." << std::endl;
		exit(-1);
	}
	for (auto i = 1; i < vc.size(); i = i + 2)
	{
		threads.emplace_back(std::thread(&PrimeNumber::SaveNumbers, &Obj, vc[i - 1], vc[i]));
	}
}

// Сохранить файл
void Parser::SaveResult(PrimeNumber &obj)
{
	std::ofstream saveFile;
	saveFile << "<root>\n" << "\t<primes> ";
	for (const auto & interval : obj.GetVec())
	{
		saveFile << interval << " ";
	}
	saveFile << "</primes>\n" << "</root> ";

	saveFile.close();
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
