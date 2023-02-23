#include <bits/stdc++.h>

using std::cin;
using std::cout;
// g(x) = sum_k(g(x - k) * f(k))
// G(x) = G(x) * F(x) + 1
// G(x) = G(x) * (1/1 - x - x^2) + 1
// G(x) = 
const long long SQ2 = 59713600;
const long long MOD = 1e9 + 7;

std::string s;
long long n;

long long qpow(long long x, long long y)
{
	x %= MOD;
	long long tmp = x;
	--y;
	while(y)
	{
		if (y & 1)
		{
			tmp = tmp * x % MOD;
		}
		x = x * x % MOD;
		y >>= 1;
	}
	return tmp;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	cin >> s;
	const long long len = s.size();
	for (int i = 0; i < len; ++i)
	{
		n = 10 * n + (s[i] - '0');
		n %= (MOD - 1);
	}

	cout << (((SQ2 / 4) * (qpow(1 + SQ2, n) - qpow(1 - SQ2, n)) % MOD) + MOD) % MOD;

	return 0;
}

