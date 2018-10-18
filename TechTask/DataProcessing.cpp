#include "DataProcessing.h"


// Сохранить файл
void DataProcessing::SaveResult(std::vector<int> & vectorNumbers)
{
	std::ofstream saveFile(fileResult);
	std::sort(vectorNumbers.begin(), vectorNumbers.end());

	saveFile << "<root>\n" << "\t<primes> ";
	for (const auto & interval : vectorNumbers)
	{
		saveFile << interval << " " ;
	}
	saveFile << "</primes>\n" << "</root> ";

	saveFile.close();
}