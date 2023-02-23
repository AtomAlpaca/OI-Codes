#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::stack;
using std::vector;
using std::queue;

const int INF = 0x3f3f3f3f;
const int MAX = 2e5 + 5;

struct Edge
{
	int x, y, w;
};

int cnt, sum, n, m, u, v, w;
stack <int> s;
vector <int> e[MAX];
vector <Edge> g, h[MAX];
vector <int> we;
int dfn[MAX], low[MAX], bl[MAX];
int dis[MAX];
bool in[MAX];
void dfs(int x)
{
	dfn[x] = low[x] = ++cnt;
	in[x] = true;
	s.push(x);

	const int len = e[x].size();
	for (int i = 0; i < len; ++i)
	{
		const int y = e[x].at(i);
		if (!dfn[y])
		{
			dfs(y);
			low[x] = std::min(low[x], low[y]);
		}
		else if (in[y])
		{
			low[x] = std::min(low[x], dfn[y]);
		}
	}

	if (dfn[x] == low[x])
	{
		++sum;
		while (true)
		{
			int p = s.top();
			in[p] = false;
			bl[p] = sum;
			s.pop();
			if (p == x)
			{
				break;
			}
		}
	}
	return ;
}

void dfs2(int x)
{
	dis[x] = 0;
	queue <int> qu;
	qu.push(x);
	while (!qu.empty())
	{
		int a = qu.front();
		qu.pop();
		const int len = h[a].size();
		for (int i = 0; i < len; ++i)
		{
			int b = h[a].at(i).y;
			dis[b] = std::min(dis[b], dis[a] + h[a].at(i).w);
			qu.push(b);
		}
	}
	return ;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v >> w;
		e[u].push_back(v);
		g.push_back(Edge{u, v, w});
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!dfn[i])
		{
			dfs(i);
		}
	}

	for (int i = 1; i <= sum; ++i)
	{
		dis[i] = INF;
	}
	dis[bl[1]] = 0;

	const int len = g.size();
	for (int i = 0; i < len; ++i)
	{
		int x = g[i].x, y = g[i].y, z = g[i].w;
		if (bl[x] != bl[y])
		{
			h[bl[x]].push_back(Edge{bl[x], bl[y], z});
		//	cout << bl[x] << ' ' << bl[y] << ' ' << z << '\n';
		}
	}

	dfs2(bl[1]);

	cout << dis[bl[n]];
}

