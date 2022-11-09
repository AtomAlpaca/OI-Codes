#include <iostream>
#include <vector>

using std::cin;
using std::cout;

const int MAX = 105;

int n, q, u, v, w;

struct Edge
{
	int v, w;
};

int siz[MAX];
int f[MAX][MAX];
std::vector <Edge> e[MAX];

void add(int x, int y)
{
	e[x].push_back({y, w});
	e[y].push_back({x, w});
	return ;
}

void dfs(int x, int fa)
{
	siz[x] = 1;

	for (Edge i : e[x])
	{
		if (i.v != fa)
		{
			dfs(i.v, x);
			siz[x] += siz[i.v];
			for (int j = std::min(q, siz[x]); j >= 1; --j)
			{
				for (int k = std::min(q, j - 1); k >= 0; --k)
				{
					f[x][j] = std::max(f[x][j], f[x][j - k - 1] + f[i.v][k] + i.w);
				}
			}
		}
	}
	return ;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> q;

	for (int i = 1; i <= n - 1; ++i)
	{
		cin >> u >> v >> w;
		add(u, v);
	}

	dfs(1, 0);

	cout << f[1][q];

	return 0;
}

