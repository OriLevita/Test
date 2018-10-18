#include "DataProcessing.h"
#include <fstream>

void DataProcessing::SaveResult(std::vector<int> const & vectorNumbers)
{
	std::ofstream saveFile(fileResult);

	saveFile << "<root>\n" << "\t<primes> ";
	for (const auto & interval : vectorNumbers)
	{
		saveFile << interval << " ";
	}
	saveFile << "</primes>\n" << "</root> ";

	saveFile.close();
}