#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 105;
const int MAXX = 2e3 + 5;
const int MOD = 998244353;

long long cnt, n, m;
long long a[MAX][MAXX];
long long s[MAX];
long long f[MAX][MAXX], g[MAX][MAXX << 1];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> a[i][j];
			s[i] = (s[i] + a[i][j]) % MOD;
		}
	}
	f[0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			f[i][j] = (f[i - 1][j]) % MOD;
			if (j > 0)
			{
				f[i][j] = (f[i][j] + f[i - 1][j - 1] * s[i] % MOD) % MOD;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cnt = (cnt + f[n][i]) % MOD;
	}
//	cout << cnt;
// floor(n / 2)
	for (int k = 1; k <= m; ++k)
	{
		for (int i = 0; i <= n; ++i)
		{
			for (int j = 0; j <= 2 * n; ++j)
			{
				g[i][j] = 0;
			}
		}
		g[0][n] = 1;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = n - i; j <= n + i; ++j)
			{
	
				g[i][j] = (g[i - 1][j] % MOD
						+  g[i - 1][j + 1] * (s[i] - a[i][k]) % MOD
						+  g[i - 1][j - 1] * a[i][k] % MOD) % MOD;
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			cnt = (cnt - g[n][n + i]) % MOD;
		}
	}
	

	cout << ((cnt % MOD) + MOD) % MOD;
	return 0;
}

