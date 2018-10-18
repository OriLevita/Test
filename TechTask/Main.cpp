#include "Parser.h"
#include "PrimeNumber.h"
#include "DataProcessing.h"

int main()
{
		std::string fileParse = "TestXml.xml";
		std::string saveFile = "Result.xml";

		PrimeNumber Prime;
		Parser ParsFile;

		DataProcessing DataProcess;
		std::vector<int> vectorValues;

		ParsFile.CheckFile(fileParse, Prime.GetVectorIntervals());

		Prime.FillVector(vectorValues);

		DataProcess.SaveResult(vectorValues);

		std::cout << "Operation complited." << std::endl;
	
	return 0;
}

