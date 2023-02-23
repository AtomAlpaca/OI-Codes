#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;

long long n, s, a, b, t, ans;
const int MAX = 5e5 + 5;

struct Edge
{
	long long x, w;
};

long long f[MAX];
vector <Edge> e[MAX];

void dfs(int x, int fa)
{
	const int len = e[x].size();
	for (int i = 0; i < len; ++i)
	{
		if (e[x].at(i).x == fa)
		{
			continue;
		}
		dfs(e[x].at(i).x, x);
		f[x] = std::max(f[x], e[x].at(i).w + f[e[x].at(i).x]);
	}

	for (int i = 0; i < len; ++i)
	{	
		if (e[x].at(i).x == fa)
		{
			continue;
		}
		ans += f[x] - e[x].at(i).w - f[e[x].at(i).x];
	}
	return ;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> s;
	for (int i = 1; i <= n - 1; ++i)
	{
		cin >> a >> b >> t;
		e[a].push_back(Edge{b, t});
		e[b].push_back(Edge{a, t});
	}

	dfs(s, -1);

	cout << ans;
}


