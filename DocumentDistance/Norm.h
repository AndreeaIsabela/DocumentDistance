#pragma once
#include<fstream>
#include<map>
#include<algorithm>
#include<iterator>
#include<functional>
#include<numeric>

using namespace std;


class Norm
{
public:
	double ComputeNorm(const map<string, int> & wordOcc);


};

