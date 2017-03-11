#include <math.h>
#include<iostream>
#include "FileReader.h"
#include"Norm.h"

using namespace std; 

int main(int argc, char *argv[])

{	
	if (argc!=2)
	{
		cout << "You need to give two files!";
		return 0;
	}

	FileReader reader;

	string s;
	map<string, int> wordOcc1 = reader.GetFrequencies(argv[1]);
	map<string, int> wordOcc2 = reader.GetFrequencies(argv[2]);

	int scal = accumulate(wordOcc1.begin(), wordOcc1.end(), 0,
						  [&](int prev, pair<string, int> scalar)
						  {
						  	return prev + scalar.second*wordOcc2[scalar.first];
						  });

	Norm calculator;
	auto length1 = calculator.ComputeNorm(wordOcc1);
	auto length2 = calculator.ComputeNorm(wordOcc2);
	auto dist = scal / (sqrt(length1) * sqrt(length2));

	cout <<float(int(dist*10000))/100  << "%\n";

	system("pause");
	return 0;
}