#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 16005;
const int INF = 0x3f3f3f3f;
int n, a, b, ans = -INF;
std::vector <int> e [MAX];

int val[MAX], f[MAX];

void add(int u, int v)
{
	e[u].push_back(v);
	e[v].push_back(u);
	return ;
}

void dfs(int x, int fa)
{
	f[x] = val[x];
	const int len = e[x].size();

	for (int i = 0; i < len; ++i)
	{
		if (e[x].at(i) != fa)
		{
			dfs(e[x].at(i), x);
			f[x] = std::max(f[x], f[x] + f[e[x].at(i)]);
		}
	}

	return ;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> val[i];
	}

	for (int i = 1; i < n; ++i)
	{
		cin >> a >> b;
		add(a, b);
	}

	dfs(1, 0);
	for (int i = 1; i <= n; ++i)
	{
		ans = std::max(ans, f[i]);
	}

	cout << ans;

	return 0;
}

