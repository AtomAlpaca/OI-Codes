#include <iostream>
using std::cout;
using std::cin;

int main()
{
	int * n = new int;
	cin >> *n;
	int nums[*n + 1][2];
	for (int i = 0; i < *n; ++i)
	{
		cin >> nums[i][0] >> nums[i][1];
	}
	nums[*n][0] = nums[0][0];
	nums[*n][1] = nums[0][0];
	int ans = 0;
	for (int i = 1; i <= *n; ++i)
	{
		ans += nums[i][1] * nums[i - 1][0] - nums[i][0] * nums[i - 1][1];
	}
	ans /= 2;
	cout << ans;
	return 0;
}
