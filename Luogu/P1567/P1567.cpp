#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int * n = new int;
	int max = 0;
	int sum = 1;
	cin >> *n;
	int nums[*n];
	for (int i = 0; i < *n; ++i)
	{
		cin >> nums[i];
		if (nums[i] > nums[i - 1] and i != 0)
		{
			++sum;
			if (sum > max)
			{
				max = sum;
			}
		}
		else
		{
			sum = 1;
		}
	}
	cout << max;
	return 0;
}