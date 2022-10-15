#include <iostream>
#include <vector>

using std::cin;
using std::cout;

const int MAX = 100005;
const long long INF = (1 << 30) - 1;
struct Heap
{
	int tot;
	int u[MAX], dis[MAX];

	void pushup(int x)
	{
		while (dis[x >> 1] > dis[x] and x > 1)
		{
			std::swap(dis[x], dis[x >> 1]);
			std::swap(u[x], u[x >> 1]);
			x >>= 1;
		}
		return ;
	}

	void pushdown(int x)
	{
		while (true)
		{
			int y = x;
			if (dis[y] > dis[x << 1 | 1] and (x << 1 | 1) <= tot)
			{
				y = x << 1 | 1;
			}
			if (dis[y] > dis[x << 1] and (x << 1) <= tot)
			{
				y = x << 1;
			}
			if (y == x)
			{
				return ;
			}
			std::swap(dis[y], dis[x]);
			std::swap(u[y], u[x]);
			x = y;
		}
	}

	void add(int p, int w)
	{
		++tot;
		u[tot] = p;
		dis[tot] = w;
		pushup(tot);
		return ;
	}

	int top()
	{
		return u[1];
	}

	void pop()
	{
		std::swap(dis[1], dis[tot]);
		std::swap(u[1], u[tot]);

		--tot;
		pushdown(1);
		return ;
	}
} h;

struct Edge
{
	int v, w;
};

std::vector <Edge> e[200005];

int s, t, st, w, n, m;
bool vis[MAX];
long long dis[MAX];


void add(int u, int v, int w)
{
	e[u].push_back({v, w});
	return ;
}

void init()
{
	for (int i = 0; i < MAX; ++i)
	{
		dis[i] = INF;
	}
	return ;
}

void dist(int x)
{
	dis[x] = 0;
	
	h.add(x, 0);

	while (h.tot)
	{
		int u = h.top();
		h.pop();
		
		if (vis[u])
		{
			continue;
		}
		const int len = e[u].size();

		for (int j = 0; j < len; ++j)
		{
			const int v = e[u].at(j).v;
			const int w = e[u].at(j).w;
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				if (!vis[v])
				{
					h.add(v, dis[v]);
				}
			}
		}
		vis[u] = true;
	}
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
