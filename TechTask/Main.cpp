#include "Parser.h"
#include "PrimeNumber.h"


int main()
{
	std::string fileParse = "TestXml.xml";
	std::string saveFile = "Result.xml";

	PrimeNumber prime;
	Parser ParsFile;

	std::vector<std::thread> threads;
	std::vector<int> vcValue;

	ParsFile.ReadFile(fileParse);
	ParsFile.FillVector(vcValue, threads, prime);

	for (auto & th : threads)
		th.join();

	ParsFile.SaveResult(prime);

	std::cout << "Operation complited." << std::endl;
	return 0;
}