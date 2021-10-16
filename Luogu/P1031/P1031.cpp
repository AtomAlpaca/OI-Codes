#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int * n = new int;
	cin >> *n;
	int nums[*n];
	long long add = 0;
	int ans = 0;
	for (int i = 0; i < *n; ++i)
	{
		cin >> nums[i];
		add += nums[i];
	}
	add /= *n;
	for (int i = 0; i < *n; ++i)
	{
		nums[i] -= add;
	}
	for (int i = 0; i < *n; ++i)
	{
		if (nums[i] == 0)
		{
			continue;
		}
		else
		{
			++ans;
			nums[i + 1] -= (0 - nums[i]);
			nums[i] = 0;
		}
	}
	cout << ans;

	delete n;
	return 0;
}