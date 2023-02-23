#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 1e5 + 5;
const int M = 1e5;
const long long MOD = 998244353;
int T, n;
std::string s;
long long f[MAX], g[MAX];

long long p(long long x, long long y)
{
	long long tmp = 1;
	while (y)
	{
		if (y & 1)
		{
			tmp *= x;
			tmp %= MOD;
		}
		y >>= 1;
		x = x * x % MOD;
	}
	return tmp;
}

void init()
{
	f[0] = g[0] = 1;
	for (long long i = 1; i <= M; ++i)
	{
		f[i] = f[i - 1] * i % MOD;
	}
	g[M] = p(f[M], MOD - 2);
	for (long long i = M - 1; i >= 1; --i)
	{
		g[i] = g[i + 1] * (i + 1) % MOD;
	}
	return ;
}

long long c(long long x, long long y)
{
	return (f[y] * g[x] % MOD) * g[y - x] % MOD;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	init();
	cin >> T;

	while (T--)
	{
		long long t1 = 0, t2 = 0, t3 = 0;
		cin >> n >> s;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == '0')
			{
				++t3;
				t2 += (t1 >> 1);
				t1 = 0;
			}
			else
			{
				++t1;
			}
		}
		t2 += (t1 >> 1);
		cout << c(t2, t2 + t3) % MOD << '\n';
	}
}
