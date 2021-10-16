#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int * n = new int;
	cin >> *n;
	short nums[*n];
	double sum;
	for (int i = 0; i < *n; ++i)
	{
		cin >> nums[i];
	}
	sort(nums,nums + *n);
	for (int i = 1; i < *n - 1; ++i)
	{
		sum += nums[i];
	}
	sum /= (*n - 2);
	printf("%.2f",sum);
	delete n;
	return 0;
}