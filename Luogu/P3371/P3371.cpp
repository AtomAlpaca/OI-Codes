#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int INF = (1 << 31) - 1;
const int MAX = 500055;

int n, m, st;
int s, t, w;

struct Edge
{
	int v, w;
};

std::vector <Edge> e[MAX];

bool vis[10005];
long long dis[10005];

void add(int u, int v, int w)
{
	e[u].push_back({v, w});
	return ;
}

void init()
{
	for (int i = 0; i <= 10000; ++i)
	{
		dis[i] = INF;
	}
	return ;
}

void dist(int s)
{
	dis[s] = 0;
	
	for (int i = 1; i <= n; ++i)
	{
		int u = 0, min = INF;
		for (int j = 1; j <= n; ++j)
		{
			if (!vis[j] and dis[j] < min)
			{
				u = j;
				min = dis[j];
			}
		}
		vis[u] = true;
		const int len = e[u].size();
		for (int j = 0; j < len; ++j)
		{
			const int v = e[u].at(j).v;
			const int w = e[u].at(j).w;
			dis[v] = std::min(dis[v], dis[u] + w);
		}
	}
	return ;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n >> m >> st;
	for (int i = 1; i <= m; ++i)
	{
		cin >> s >> t >> w;
		add(s, t, w);
	}

	init();
	dist(st);

	for (int i = 1; i <= n; ++i)
	{
		cout << dis[i] << ' ';
	}

	return 0;
}
