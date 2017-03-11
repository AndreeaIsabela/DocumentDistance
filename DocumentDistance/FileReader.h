#pragma once
#include <map>
#include <string>
#include<fstream>

using namespace std;

class FileReader
{
public:
	map<string, int> GetFrequencies(string fileName);
};