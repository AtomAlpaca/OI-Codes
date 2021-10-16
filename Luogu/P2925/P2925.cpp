#include <iostream>

using std::cin;
using std::cout;

int c, h;
int val[5005], dp[50005];

int main(int argc, char const *argv[])
{
	cin >> c >> h;

	for (int i = 0; i < h; ++i)
	{
		cin >> val[i];
	}

	for (int i = 0; i < h; ++i)
	{
		for (int j = c; j >= val[i]; --j)
		{
			dp[j] = std::max(dp[j], dp[j - val[i]] + val[i]);
		}
	}

	cout << dp[c];
	return 0;
}