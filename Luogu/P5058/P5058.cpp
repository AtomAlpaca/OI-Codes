#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;

const int MAX = 2e5 + 5;

int n, a, b, cnt;
int dfn[MAX], low[MAX];
vector <int> ans, e[MAX];

bool cmp(int x, int y)
{
	return x < y;
}

void dfs(int x, int fa)
{
	++cnt;
	dfn[x] = low[x] = cnt;
	const int len = e[x].size();
	int tmp = 0;
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

		if (!dfn[y])
		{
			dfs(y, x);
			low[x] = std::min(low[x], low[y]);
			if (low[y] >= dfn[x] and x != a and x != b)
			{
				if (dfn[b] >= dfn[y])
				{
					ans.push_back(x);
				}
			}
		}
		else
		{
			low[x] = std::min(low[x], dfn[y]);
		}
	}
	return ;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	cin >> n;
	while (true)
	{
		cin >> a >> b;
		if (a == 0 and b == 0)
		{
			break;
		}
		e[a].push_back(b);
		e[b].push_back(a);
	}

	cin >> a >> b;

	dfs(a, -1);

	std::sort(ans.begin(), ans.end(), cmp);
	if (ans.size())
	{
		cout << ans.at(0);
		return 0;
	}

	cout << "No solution";

	return 0;
}

