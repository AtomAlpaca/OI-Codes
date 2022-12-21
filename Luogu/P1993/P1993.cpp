#include <iostream>

using std::cin;
using std::cout;

const int MAX = 5e3 + 5;

struct Edge
{
	int u, v, w;
} e[MAX << 1];

int n, m, t, tot, u, v, w;
int dis[MAX];

bool floyd()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= tot; ++j)
		{
			dis[e[j].v] = std::min(dis[e[j].v], dis[e[j].u] + e[j].w);
		}
	}

	for (int j = 1; j <= tot; ++j)
	{
		if (dis[e[j].v] > dis[e[j].u] + e[j].w)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= m; ++i)
	{
		cin >> t >> u >> v;
		if (t == 1)
		{
			cin >> w;
			++tot;
			e[tot].v = v;
			e[tot].u = u;
			e[tot].w = -w;
		}
		else if (t == 2)
		{
			cin >> w;
			++tot;
			e[tot].v = u;
			e[tot].u = v;
			e[tot].w = w;
		}
		else
		{
			++tot;
			e[tot].v = v;
			e[tot].u = u;
			e[tot].w = 0;
			++tot;
			e[tot].v = u;
			e[tot].u = v;
			e[tot].w = 0;
		}
	}

	if (floyd())
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
}
