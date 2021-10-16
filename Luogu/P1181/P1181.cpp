#include <iostream>

using std::cin;
using std::cout;

int main()
{
	int * n = new int;
	int m, ans = 0, sum = 0;
	cin >> *n >> m;

	int nums[*n] = {0};

	for (int i = 0; i < *n; ++i)
	{
		cin >> nums[i];
		sum += nums[i];
		if (sum > m)
		{
			++ans;
			sum = nums[i];
		}
	}
	++ans;

	cout << ans;

	delete n;

	return 0;
}
