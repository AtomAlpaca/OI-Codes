#include <iostream>

using std::cin;
using std::cout;

const long long MAX = 20000528 + 5;
long long MOD, n;
long long num[MAX], pans[MAX];

void init(long long x)
{
	num[0] = 1;
	for (int i = 1; i <= x; ++i)
	{
		num[i] = num[i - 1] * i % MOD;
	}
	return ;
}

long long qpow(long long a, long long x)
{
	long long ans = 1;
	while (x)
	{
		if (x & 1)
		{
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		x >>= 1;
	}
	return ans;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> MOD;
	
	init(n);
	
	pans[n] = qpow(num[n], MOD - 2);
	
	for (int i = n - 1; i >= 1; --i)
	{
		pans[i] = (pans[i + 1] * (i + 1)) % MOD;
	}

	for (int i = 1; i <= n; ++i)
	{
		cout << (pans[i] * num[i - 1]) % MOD << '\n';
	}

	return 0;
}
