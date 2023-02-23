#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;

const int MAX = 5e4 + 5;

struct Edge
{
	int x, y;
	bool f;
};

vector <Edge> eg;
vector <int> e[MAX];
int cnt, n, m, a, b, sum;
int dfn[MAX], low[MAX];
void dfs(int x, int fa)
{
	++cnt;
	dfn[x] = low[x] = cnt;
	const int len = e[x].size();
	int tmp = 0;

	for (int i = 0; i < len; ++i)
	{
		int y;
		if (eg[e[x].at(i)].y == x)
		{
			y = eg[e[x].at(i)].x;
		}
		else
		{
			y = eg[e[x].at(i)].y;
		}
		if (y == fa and !tmp)
		{
			++tmp;
			continue;
		}
		if (!dfn[y])
		{
			dfs(y, x);
			low[x] = std::min(low[x], low[y]);
			if (low[y] > dfn[x])
			{
				eg[e[x].at(i)].f = true;
			}
		}
		else
		{
			low[x] = std::min(low[x], dfn[y]);
		}
	}
	return ;
}

bool vis[MAX];
int id[MAX];
int num;
int d[MAX];

void dfs2(int x)
{
	vis[x] = true;
	id[x] = num;
	const int len = e[x].size();

	for (int i = 0; i < len; ++i)
	{
		int y;
		if (eg[e[x].at(i)].y == x)
		{
			y = eg[e[x].at(i)].x;
		}
		else
		{
			y = eg[e[x].at(i)].y;
		}
		if (vis[y] or eg[e[x].at(i)].f)
		{
			continue;
		}
		dfs2(y);
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> a >> b;
		eg.push_back(Edge{a, b, false});
		e[a].push_back(eg.size() - 1);
		e[b].push_back(eg.size() - 1);
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!dfn[i])
		{
			dfs(i, -1);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i])
		{
			++num;
			dfs2(i);
		}
	}
	const int len = eg.size();
	for (int i = 0; i < len; ++i)
	{
		if (eg[i].f)
		{
			//cout << eg[i].x << ' ' << eg[i].y << '\n';
			++d[id[eg[i].x]];
			++d[id[eg[i].y]];
		}
	}

	for (int i = 1; i <= num; ++i)
	{
		if (d[i] == 1)
		{
			++sum;
		}
	}

	cout << (sum + 1) / 2;
	return 0;
}

