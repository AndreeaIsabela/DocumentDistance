#include<fstream>
#include<map>
#include<algorithm>
#include <math.h>
#include<string>
#include<iostream>
#include<vector>
#include<numeric>
#include<functional>
#include <iterator>

using namespace std; 

map<string, int> ReadFile(string filePath)
{	
	map<string, int> wordOcc;
	string s;
	ifstream in1(filePath);

	while (in1 >> s)
	{
		wordOcc[s]++;
	}

	return wordOcc;
}

double ComputeNorm(const map<string, int> & wordOcc)
{
	
	return accumulate(wordOcc.begin(), wordOcc.end(),0.0,
					  [](double prev, pair<string, int> pair)
					  {
					  	return prev+pow(pair.second,2);
					  });
}



int main(int argc, char *argv[])

{	
	if (argc!=2)
	{
		cout << "You need to give two files!";
		return 0;
	}
	ifstream in1(argv[1]);
	ifstream in2(argv[2]);

	string s;
	vector<int> scalar;
	map<string, int> wordOcc1=ReadFile(argv[1]);
	map<string, int> wordOcc2=ReadFile(argv[2]);

	int scal = accumulate(wordOcc1.begin(), wordOcc1.end(), 0,
						  [&](int prev, pair<string, int> scalar)
						  {
						  	return prev + scalar.second*wordOcc2[scalar.first];
						  });

	auto length1 = ComputeNorm(wordOcc1);
	auto length2 = ComputeNorm(wordOcc2);
	auto dist = scal / (sqrt(length1) * sqrt(length2));

	cout <<float(int(dist*10000))/100  << "%\n";

	system("pause");
	return 0;
}