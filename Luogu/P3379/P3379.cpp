#include <iostream>
#include <vector>

using std::cin;
using std::cout;

const int MAX = 5e5 + 5;

int n, m, s, u, v;
std::vector <int> e[MAX];
int d[MAX];
int f[MAX][25];

void dfs0(int x, int fa)
{
	d[x] = d[fa] + 1;
	f[x][0] = fa;
	for (int i = 1; i <= 20; ++i)
	{
		f[x][i] = f[f[x][i - 1]][i - 1];
	}

	const int len = e[x].size();

	for (int i = 0; i < len; ++i)
	{
		if (e[x].at(i) != fa)
		{
			dfs0(e[x].at(i), x);
		}
	}
	return ;
}

int dfs(int x, int y)
{
	if (d[x] > d[y])
	{
		std::swap(x, y);
	}

	int delta = d[y] - d[x];

	for (int i = 0; delta; ++i, delta >>= 1)
	{
		if (delta & 1)
		{
			y = f[y][i];
		}
	}

	if (x == y)
	{
		return x;
	}

	for (int i = 20; i >= 0; --i)
	{
		if (f[x][i] != f[y][i])
		{
			x = f[x][i];
			y = f[y][i];
		}
	}
	if (x == s)
	{
		return x;
	}
	return f[x][0];

}

int main()
{
	cin >> n >> m >> s;
	
	for (int i = 1; i < n; ++i)
	{
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	dfs0(s, 0);

	while (m--)
	{
		cin >> u >> v;
		cout << dfs(u, v) << '\n';
	}

	return 0;
}
