#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;
using std::stack;

const int MAX = 16e3 + 5;
int cnt, sum, n, m, a, b;
int dfn[MAX], low[MAX], bl[MAX];
bool in[MAX];
vector <int> e[MAX];
stack <int> s;

void dfs(int x)
{
	dfn[x] = low[x] = ++cnt;
	in[x] = true;
	s.push(x);

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
		while (true)
		{
			int p = s.top();
			in[p] = false;
			bl[p] = sum;
			s.pop();
			if (p == x)
			{
				break;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> a >> b;
		int x, y;
		if (a % 2)
		{
			x = a + 1;
		}
		else
		{
			x = a - 1;
		}
		if (b % 2)
		{
			y = b + 1;
		}
		else
		{
			y = b - 1;
		}
		e[b].push_back(x);
		e[a].push_back(y);
	}

	for (int i = 1; i <= 2 * n; ++i)
	{
		if (!dfn[i])
		{
			dfs(i);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (bl[i * 2] == bl[i * 2 - 1])
		{
			cout << "NIE\n";
			return 0;
		}
	}

	for (int i = 1; i <= 2 * n; i += 2)
	{
		if (bl[i] < bl[i + 1])
		{
			cout << i << '\n';
		}
		else
		{
			cout << i + 1 << '\n';
		}
	}
	return 0;
}

