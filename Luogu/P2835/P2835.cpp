#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;
using std::stack;

struct Edge
{
	int x, y;
};

const int MAX = 205;

int n, m, cnt, sum, ans;
vector <Edge> g;
vector <int> e[MAX];
stack <int> s;
int dfn[MAX], low[MAX], bl[MAX], d[MAX];
bool in[MAX];

void dfs(int x)
{
	++cnt;
	dfn[x] = low[x] = cnt;
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
		while (s.top() != x)
		{
			in[s.top()] = false;
			bl[s.top()] = sum;
			s.pop();
		}
		s.pop();
		in[x] = false;
		bl[x] = sum;
	}
}


int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		while (true)
		{
			cin >> m;
			if (m == 0)
			{
				break;
			}
			e[i].push_back(m);
			g.push_back(Edge{i, m});
		}
	}	
	
	for (int i = 1; i <= n; ++i)
	{
		if (!dfn[i])
		{
			dfs(i);
		}
	}

	const int len = g.size();
	for (int i = 0; i < len; ++i)
	{
		const int x = g.at(i).x, y = g.at(i).y;
		if (bl[x] != bl[y])
		{
			++d[bl[y]];
		}
	}
	
	for (int i = 1; i <= sum; ++i)
	{
		if (d[i] == 0)
		{
			++ans;
		}
	}
	cout << ans;

}

