#include <bits/stdc++.h>

using std::cin;
using std::cout;

int n;
const int MAX = 6005;

std::vector <int> e[MAX];

bool p[MAX];
int r[MAX], u, v, rt;
int f[MAX][2]; //0 -> not

void add(int x, int y)
{
	e[x].push_back(y);
	e[y].push_back(x);
	return ;
}

void dfs(int x, int fa)
{
	if (e[x].empty())
	{
		f[x][1] = r[x];
		f[x][0] = 0;
		return ;
	}

	const int len = e[x].size();
	int cnt1 = 0, cnt0 = 0;
	for (int i = 0; i < len; ++i)
	{
		int to = e[x].at(i);
		if (to != fa)
		{
			dfs(to, x);
			if (f[to][1] > 0)
			{
				cnt1 += f[to][1];
			}
			if (f[to][0] > 0)
			{
				cnt0 += f[to][0];
			}
		}
	}

	f[x][1] = cnt0;
	if (r[x] > 0)
	{
		f[x][1] += r[x];
	}
	f[x][0] = cnt1;
	//cout << x << ' ' << f[x][1] << ' ' << f[x][0] << '\n';
	return ;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> r[i];
		f[i][1] = r[i];
	}

	for (int i = 1; i < n; ++i)
	{
		cin >> u >> v;
		add(u, v);
		p[u] = true;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!p[i])
		{
			rt = i;
		}
	}

	dfs(rt, 0);

	cout << std::max(f[rt][0], f[rt][1]);
	return 0;
}

