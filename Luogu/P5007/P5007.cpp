#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;

const long long MOD = 100000007;
const int MAX = 1e6 + 5;

long long n, T, u, v;
long long w[MAX], f[MAX], g[MAX];

vector <int> e[MAX];

void dfs(int x, int fa)
{
	for (int i : e[x])
	{
		if (i == fa)
		{
			continue;
		}
		dfs(i, x);
		f[x] = ((f[i] * (g[x] + 1)) % MOD + (f[x] * (g[i] + 1) % MOD)) % MOD;
		g[x] = ((g[x] + g[i]) % MOD + (g[x] * g[i]) % MOD) % MOD;
	}
	++g[x];
	f[x] += w[x];
	g[x] %= MOD;
	f[x] %= MOD;
	return ;
}

int main()
{
	cin >> n >> T;
	if (T == 0)
	{
		for (int i = 1; i <= n; ++i)
		{
			w[i] = 1;
		}
	}
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			w[i] = i;
		}
	}

	for (int i = 1; i < n; ++i)
	{
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	dfs(1, 0);

	cout << f[1];
	return 0;
}

