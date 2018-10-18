#include "Parser.h"
#include "PrimeNumber.h"
#include "DataProcessing.h"

int main()
{
	std::string fileParse = "TestXml.xml";
	std::string saveFile = "Result.xml";

	Parser ParsFile;
	PrimeNumber Prime;
	DataProcessing DataProcess(saveFile);

	std::vector<int> vectorValues;

	ParsFile.CheckFile(fileParse, Prime.GetVectorIntervals());

	Prime.FillVector(vectorValues);

	std::sort(vectorValues.begin(), vectorValues.end());

	DataProcess.SaveResult(vectorValues);

	std::cout << "Operation complited." << std::endl;

	return 0;
}
