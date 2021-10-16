#include <iostream>

using std::cout;
using std::cin;

int main()
{
	int * n = new int;
	long long x, ans = 0;
	
	cin >> *n >> x;
	long long nums[*n];

	for (int i = 0; i < *n; ++i)
	{
		cin >> nums[i];
	}

	if (nums[0] > x)
	{
		ans += nums[0] - x;
		nums[0] = x;
	}
	for (int i = 1; i < *n; ++i)
	{
		if (nums[i] + nums[i - 1] > x)
		{
			ans += nums[i] + nums[i - 1] - x;
			nums[i] = x - nums[i - 1];
		}
		/*
		while (nums[i] + nums[i - 1] > x)
		{
			--nums[i];
			++ans;
		}*/
	}

	cout << ans;

	delete n;
	return 0;
}
