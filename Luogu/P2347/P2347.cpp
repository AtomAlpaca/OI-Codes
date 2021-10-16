#include <iostream>

using std::cin;
using std::cout;

const int NUMS[6] = {1, 2, 3, 5, 10, 20};

int n, num = 0, ans;
int val[1005], dp[1005];

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 6; ++i)
	{
		cin >> n;
		for (int j = 0; j < n; ++j)
		{
			val[num] = NUMS[i];
			++num;
		}
	}

	dp[0] = 1;
	for (int i = 0; i < num; ++i)
	{
		for (int j = 1000; j >= 0; --j)
		{
			if (dp[j] != 0)
			{
				dp[j + val[i]] += 1;
			}
		}
	}

	for (int i = 1; i <= 1000; ++i)
	{
		if (dp[i] != 0)
		{
			++ans;
		}
	}

	cout << "Total=" << ans;
	return 0;
}