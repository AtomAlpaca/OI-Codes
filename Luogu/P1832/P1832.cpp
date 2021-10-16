#include <cmath>
#include <iostream>

using std::cin;
using std::cout;

int n, num = 0;
long long prime[1005], dp[1005];

bool isPrime(int x)
{
	for (int i = 2, max = std::sqrt(x); i <= max; ++i)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	if (x == 2 or x == 3 or x == 5 or x == 7)
	{
		return true;
	}
	if (x % 2 == 0 or x == 1)
	{
		return false;
	}
	return true;
}

void getPrime(int max)
{
	for (int i = 2; i <= max; ++i)
	{
		if (isPrime(i))
		{
			prime[num] = i;
			++num;
		}
	}
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	getPrime(n);

	dp[0] = 1;

	// for (int i = 0; i < num; ++i)
	// {
	// 	cout << prime[i] << '\n';
	// }

	for (int i = 0; i < num; ++i)
	{
		for (int j = prime[i]; j <= n; ++j)
		{
			dp[j] += dp[j - prime[i]];
		}
	}

	cout << dp[n];
	return 0;
}