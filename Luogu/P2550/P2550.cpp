#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int * n = new int;
	cin >> *n;
	int prise[7];
	int ans[7] = {0};
	for (int i = 0; i < 7; ++i)
	{
		cin >> prise[i];
	}
	int nums[*n][7];
	int sum = 0;
	for (int i = 0; i < *n; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			cin >> nums[i][j];
			for (int k = 0; k < 7; ++k)
			{
				if (nums[i][j] == prise[k])
				{
					++sum;
				}
			}
		}
		++ans[7 - sum];
		sum = 0;
	}
	for (int i = 0; i < 7; ++i)
	{
		cout << ans[i] << " ";
	}
	delete n;
	return 0;
}