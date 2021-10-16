#include <iostream>

using std::cin;
using std::cout;

int m, n;
int val[10005], tim[10005], dp[10005];

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> val[i] >> tim[i];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = tim[i]; j <= m; ++j)
		{
			dp[j] = std::max(dp[j], dp[j - tim[i]] + val[i]);
		}
	}

	cout << dp[m];
	return 0;
}