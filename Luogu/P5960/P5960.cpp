#include <iostream>

using std::cin;
using std::cout;

const int MAX = 5e3 + 5;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int u, v, w;
} e[MAX];

int dis[MAX];
int n, m;

bool floyd()
{
	for (int i = 1; i <= n - 1; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			dis[e[j].v] = std::min(dis[e[j].v], dis[e[j].u] + e[j].w);
		}
	}

	for (int i = 1; i <= m; ++i)
	{
		if (dis[e[i].v] > dis[e[i].u] + e[i].w)
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
		cin >> e[i].v >> e[i].u >> e[i].w;
	}

	if (floyd())
	{
		for (int i = 1; i <= n; ++i)
		{
			cout << dis[i] << ' ';
		}
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
