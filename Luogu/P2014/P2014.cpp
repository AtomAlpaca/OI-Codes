#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 305;

int n, m, s, k;
int val[MAX], siz[MAX];
int f[MAX][MAX << 1];
std::vector <int> e [MAX];

void add(int x, int y)
{
	e[x].push_back(y);
	e[y].push_back(x);
	return ;
}

void dfs(int x, int fa)
{
	siz[x] = 1;
	f[x][1] = val[x];
	const int len = e[x].size();

	for (int i = 0; i < len; ++i)
	{
		int v = e[x].at(i);
		if (v != fa)
		{
			dfs(v, x);
			for (int j = m + 1; j >= 1; --j)
			{
				for (int k = 1; k <= j - 1; ++k)
				{
					f[x][j] = std::max(f[x][j], f[x][j - k] + f[v][k]);
				}
			}
			siz[x] += siz[v];
		}
	}
}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		cin >> k >> s;
		val[i] = s;
		if (k)
		{
			add(i, k);
		}
		else
		{
			add(i, 0);
		}
	}

	dfs(0, -1);

	cout << f[0][m + 1];
	return 0;
}

