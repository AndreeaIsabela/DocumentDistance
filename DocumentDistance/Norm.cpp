#include"Norm.h"

double Norm::ComputeNorm(const map<string, int>& wordOcc)
{
	return accumulate(wordOcc.begin(), wordOcc.end(), 0.0,
		[](double prev, pair<string, int> pair)
	{
		return prev + pow(pair.second, 2);
	});
}
