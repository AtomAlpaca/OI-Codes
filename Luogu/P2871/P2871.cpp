#include <iostream>

using std::cin;
using std::cout;

int n, m;
int cost[3407], val[3407], dp[12885];

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> cost[i] >> val[i];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = m; j >= cost[i]; --j)
		{
			dp[j] = std::max(dp[j], dp[j - cost[i]] + val[i]);
		}
	}

	cout << dp[m];
	return 0;
}
