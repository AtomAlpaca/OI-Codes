#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;

int n, m, k, r, tim, ans;
int val[15], cost[15], pro[15], dp[155];

bool cmp(int num1, int num2)
{
	return num1 < num2;
}

int main(int argc, char const *argv[])
{
	cin >> n >> m >> k >> r;

	for (int i = 0; i < n; ++i)
	{
		cin >> pro[i];
	}

	std::sort(pro, pro + n, cmp);

	for (int i = 0; i < m; ++i)
	{
		cin >> cost[i];
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> val[i];
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = r; j >= cost[i]; --j)
		{
			dp[j] = std::max(dp[j], dp[j - cost[i]] + val[i]);
		}
	}

	for (int i = 0; i <= r; ++i)
	{
		if (dp[i] > k)
		{
			tim = r - i;
			break;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if (pro[i] <= tim)
		{
			tim -= pro[i];
			++ans;
		}
		else
		{
			break;
		}
	}

	cout << ans;
	return 0;
}