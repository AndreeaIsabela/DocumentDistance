#include "FileReader.h"

map<string, int> FileReader::GetFrequencies(string fileName)
{
	map<string, int> wordOcc;
	string s;
	ifstream in1(fileName);

	while (in1 >> s)
	{
		wordOcc[s]++;
	}

	return wordOcc;
	
}
