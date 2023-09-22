#include<iostream>
#include<vector>
using namespace std;

long long sum(vector<int> &a)
{
	long long result = 0;
	for (int i = 0;i < a.size();i++)
	{
		result = result + a[i];
	}
	return result;
}