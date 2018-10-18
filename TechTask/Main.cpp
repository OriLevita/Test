#include "Parser.h"
#include "PrimeNumber.h"
#include "DataProcessing.h"
#include <algorithm>

int main()
{
	std::string fileParse = "TestXml.xml";
	Parser ParsFile;
	PrimeNumber Prime;
	ParsFile.CheckFile(fileParse, Prime.GetVectorIntervals());

	std::vector<int> vectorValues;
	Prime.FillVector(vectorValues);

	std::sort(vectorValues.begin(), vectorValues.end());

	std::string saveFile = "Result.xml";
	DataProcessing DataProcess(saveFile);
	DataProcess.SaveResult(vectorValues);

	std::cout << "Operation completed." << std::endl;

	return 0;
}


