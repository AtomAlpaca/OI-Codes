#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;
using std::stack;

const int MAX  = 5e5 + 5;
const int MAXX = 2e6 + 5;

vector <int> e[MAX], ans[MAX];
stack  <int> s;
int n, m, a, b, cnt, num;
int dfn[MAX], low[MAX];

void dfs(int x, int fa)
{
	++cnt;
	dfn[x] = low[x] = cnt;
	s.push(x);

	const int len = e[x].size();
	int tmp = 0, son = 0;

	for (int i = 0; i < len; ++i)
	{
		int y = e[x].at(i);
		if (y == fa)
		{
			if (!tmp)
			{
				++tmp;
				continue;
			}
		}
		++son;
		if (!dfn[y])
		{
			dfs(y, x);
			low[x] = std::min(low[x], low[y]);
			if (low[y] >= dfn[x])
			{
				++num;
				while (s.top() != y)
				{
					ans[num].push_back(s.top());
					s.pop();
				}
				s.pop();
				ans[num].push_back(y);
				ans[num].push_back(x);
			}
		}
		else
		{
			low[x] = std::min(low[x], dfn[y]);
		}
	}
	if (fa == -1 and son == 0)
	{
		num++;
		ans[num].push_back(x);
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> a >> b;
		if (a != b)
		{
			e[a].push_back(b);
			e[b].push_back(a);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!dfn[i])
		{
			dfs(i, -1);
		}
	}

	cout << num << '\n';

	for (int i = 1; i <= num; ++i)
	{
		const int len = ans[i].size();
		cout << len << ' ';
		for (int j = 0; j < len; ++j)
		{
			cout << ans[i].at(j) << ' ';
		}
		cout << '\n';
	}
	return 0;
}

