// sum l->r ((d[x] - d[i]) * v[i])
// sum l->r (d[x] * v[i] - d[i] * v[i])
// d[x] sum l->r(v[i]) - sum l->r (d[i] * v[i])
//
#include <bits/stdc++.h>

const int MOD = 19260817;

using std::cin;
using std::cout;

const int MAX = 2e5 + 5;
int n, m, l, r, x, t;
long long d[MAX], s[MAX], f[MAX];

long long lcal(long long x, long long l, long long r)
{
	long long sum1 = d[x] * (s[r] - s[l - 1]) % MOD;
	long long sum2 = (f[r] - f[l - 1]) % MOD;
	return (sum1 - sum2) % MOD;
}

long long rcal(long long x, long long l, long long r)
{
	long long sum1 = d[x] * (s[r] - s[l - 1]) % MOD;
	long long sum2 = (f[r] - f[l - 1]) % MOD;
	return (sum2 - sum1) % MOD;
}
int main()
{
	cin >> n >> m;

	for (int i = 2; i <= n; ++i)
	{
		cin >> t;
		d[i] = (d[i - 1] + t) % MOD;
	}

	for (int i = 1; i <= n; ++i)
	{
		cin >> t;
		s[i] = (s[i - 1] + t) % MOD;
		f[i] = (f[i - 1] + d[i] * t) % MOD;
	}

	while (m--)
	{
		cin >> x >> l >> r;
		if (r < x)
		{
			cout << ((lcal(x, l, r) % MOD) + MOD) % MOD;
		}
		else if (l > x)
		{
			cout << ((rcal(x, l, r) % MOD) + MOD) % MOD;
		}
		else
		{
			cout << ((((lcal(x, l, x - 1) + rcal(x, x + 1, r)) % MOD) + MOD) % MOD);
		}
		cout << '\n';
	}

	return 0;
}

