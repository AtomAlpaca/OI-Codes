#include <iostream>

using std::cin;
using std::cout;

int s;
int value[1005], dp[1005];

constexpr void valueInit(void)
{
	for (int i = 1; i < 1001; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			if (i % j == 0)
			{
				value[i] += j;
			}
		}
	}
	return ;
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	valueInit();
	
	cin >> s;

	for (int i = 1; i <= s; ++i)
	{
		for (int j = s; j >= i; --j)
		{
			dp[j] = std::max(dp[j], dp[j - i] + value[i]);
		}
	}

	cout << dp[s];
	return 0;
}