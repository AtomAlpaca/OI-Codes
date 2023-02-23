#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;
using std::stack;
const int MAX = 205;

std::string s1, s2;
stack <int> s;
vector <int> e[MAX];
int T, n, m, sum, cnt;
int dfn[MAX], low[MAX], bl[MAX];
bool in[MAX], flag;

void init()
{
	for (int i = 0; i <= 2 * n; ++i)
	{
		e[i].clear();
		low[i] = dfn[i] = in[i] = bl[i] = 0;
	}
	sum = cnt = 0;
	flag = false;
}

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
			bl[p] = sum;
			in[p] = false;
			s.pop();
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
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		init();
		for (int i = 1; i <= m; ++i)
		{
			cin >> s1 >> s2;
			int x = 0, y = 0;
			const int l1 = s1.size();
			const int l2 = s2.size();
			for (int i = 1; i < l1; ++i)
			{
				x *= 10;
				x += s1[i] - '0';
			}
			for (int i = 1; i < l2; ++i)
			{
				y *= 10;
				y += s2[i] - '0';
			}
			if (s1[0] == 'm' and s2[0] == 'm')
			{
				e[x + n].push_back(y);
				e[y + n].push_back(x);
			}
			else if (s1[0] == 'h' and s2[0] == 'm')
			{
				e[x].push_back(y);
				e[y + n].push_back(x + n);
			}
			else if (s1[0] == 'm' and s2[0] == 'h')
			{
				e[x + n].push_back(y + n);
				e[y].push_back(x);
			}
			else if (s1[0] == 'h' and s2[0] == 'h')
			{
				e[x].push_back(y + n);
				e[y].push_back(x + n);
			}
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
			if (bl[i] == bl[i + n])
			{
				cout << "BAD\n";
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "GOOD\n";
		}
	}

	return 0;
}

