#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;

const int MAX = 25;

int n, val, p;
int v[MAX], r[MAX], ans[MAX];
bool vis[MAX];
vector <int> e[MAX];

int dfs(int x, int fa)
{
	vis[x] = true;
	if (e[x].size() == 1 and e[x].at(0) == fa)
	{
		return v[x];
	}
	int mx = 0;
	const int len = e[x].size();

	for (int i = 0; i < len; ++i)
	{
		if (!vis[e[x].at(i)] and e[x].at(i) != fa)
		{
			int tmp = dfs(e[x].at(i), x);
			if (tmp > mx)
			{
				r[x] = e[x].at(i);
				mx = tmp;
			}
		}
	}
	return mx + v[x];
}

void print(int x)
{
	while (ans[x])
	{
		cout << x << ' ';
		x = ans[x];
	}
	cout << x << '\n';
	return ;
}

void init()
{
	for (int i = 1; i < MAX; ++i)
	{
		vis[i] = false;
		r[i] = 0;
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			cin >> p;
			if (p == 1)
			{
				e[i].push_back(j);
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		init();
		int a = dfs(i, 0);
		if (a > val)
		{
			val = a;
			p = i;
			for (int i = 1; i <= n; ++i)
			{
				ans[i] = r[i];
			}
		}
	}

	print(p);
	cout << val;
	return 0;
}

