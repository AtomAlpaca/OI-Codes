#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;


const int MAX = 5e4 + 5;
int cnt;
int dfn[155], low[155];

struct Edge
{
	int a, b;
};

int n, m, a, b;
vector <int> e[MAX];
vector <Edge> ke;

bool cmp(Edge e1, Edge e2)
{
	if (e1.a == e2.a)
	{
		return e1.b < e2.b;
	}
	return e1.a < e2.a;
}

void dfs(int x, int fa)
{
	++cnt;
	dfn[x] = low[x] = cnt;

	const int len = e[x].size();
	int tmp = 0;
	for (int i = 0; i < len; ++i)
	{
		if (e[x].at(i) == fa)
		{
			if (!tmp)
			{
				++tmp;
				continue;
			}
		}
		
		if (!dfn[e[x].at(i)])
		{
			dfs(e[x].at(i), x);
			if (dfn[x] < low[e[x].at(i)])
			{
				ke.push_back(Edge{x, e[x].at(i)});
			}
			low[x] = std::min(low[x], low[e[x].at(i)]);
		}
		else
		{
			low[x] = std::min(low[x], dfn[e[x].at(i)]);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!dfn[i])
		{
			dfs(i, -1);
		}
	}

	std::sort(ke.begin(), ke.end(), cmp);
	const int len  = ke.size();
	for (int i = 0; i < len; ++i)
	{
		cout << ke[i].a << ' ' << ke[i].b << '\n';
	}

	return 0;
}

