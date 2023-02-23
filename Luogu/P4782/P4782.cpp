#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;
using std::stack;
const int MAX = 1e6 + 3;

int sum, cnt, n, m, a, b, u, v;
vector <int> e[(MAX << 1) + 5];
stack <int> s;
int dfn[MAX << 1], low[MAX << 1], bl[MAX << 1];
bool in[MAX << 1];
void dfs(int x)
{
	dfn[x] = low[x] = ++cnt;
	s.push(x);
	in[x] = true;

	const int len = e[x].size();
	for (int i = 0; i < len; ++i)
	{
		int y = e[x].at(i);
		if (!dfn[y])
		{
			dfs(y);
			low[x] = std::min(low[x], low[y]);
		}
		else if (in[y])
		{
			low[x] = std::min(low[x], dfn[y]);
		}
	}

	if (dfn[x] == low[x])
	{
		++sum;
		while(true)
		{
			int p = s.top();
			s.pop();
			bl[p] = sum;
			in[p] = false;
			if (p == x)
			{
				break;
			}
		}
	}
	return ;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> a >> v >> b;
		if (a == 0 and b == 0)
		{
			e[u].push_back(v + n);
			e[v].push_back(u + n);
		}
		else if (a == 0 and b == 1)
		{
			e[u].push_back(v);
			e[v + n].push_back(u + n);
		}
		else if (a == 1 and b == 0)
		{
			e[u + n].push_back(v + n);
			e[v].push_back(u);
		}
		else if (a == 1 and b == 1)
		{
			e[u + n].push_back(v);
			e[v + n].push_back(u);
		}
	}

	for (int i = 1; i <= n * 2; ++i)
	{
		if (!dfn[i])
		{
			dfs(i);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (bl[i] == bl[i + n])
		{
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	cout << "POSSIBLE\n";
	for (int i = 1; i <= n; ++i)
	{
		if (bl[i] < bl[i + n])
		{
			cout << 1 << ' ';
		}
		else
		{
			cout << 0 << ' ';
		}
	}
	return 0;
}

