#include <iostream>

using std::cin;
using std::cout;

const long long MOD = 998244353;
const long long MAX = 37;

long long n, m, K, ans;
long long f[105][35][35][35], g[MAX], h[MAX], a[105];

long long pw(long long x, long long y)
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
	return tmp % MOD;
}

long long q(long long x)
{
	long long tmp = 0;
	while (x)
	{
		tmp += (x & 1);
		x >>= 1;
	}
	return tmp;
}

void init(int x)
{
	g[0] = h[0] = 1;
	for (int i = 1; i <= x; ++i)
	{
		g[i] = (long long)i * g[i - 1] % MOD;
	}
	h[x] = pw(g[x], MOD - 2);
	for (int i = x - 1; i >= 1; --i)
	{
		h[i] = (long long)h[i + 1] * (i + 1) % MOD;
	}
	return ;
}

long long c(long long x, long long y)
{
	return (g[y] * h[x] % MOD) * h[y - x] % MOD;
}

int main()
{
	cin >> n >> m >> K;
	for (int i = 0; i <= m; ++i)
	{
		cin >> a[i];
	}
	init(35);
	f[0][0][0][0] = 1;
	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			for (int k = 0; k <= K; ++k)
			{
				for (int l = 0; l <= (n >> 1); ++l)
				{
					for (int o = 0; o <= (n - j); ++o)
					{
						f[i + 1][j + o][k + ((l + o) % 2)][(o + l) >> 1] =
						(f[i + 1][j + o][k + ((l + o) % 2)][(o + l) >> 1] +
						(long long)(f[i][j][k][l] * pw(a[i], o) % MOD) * c(o, n - j) % MOD)%MOD;
					}
				}
			}
		}
	}

	for (int k = 0; k <= K; ++k)
	{
		for (int p = 0; p <= (n >> 1); ++p)
		{
			if (k + q(p) <= K)
			{
				ans = (ans + f[m + 1][n][k][p]) % MOD;
			}
		}
	}
	cout << ans % MOD;
	return 0;
}
