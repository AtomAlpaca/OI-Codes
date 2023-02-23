#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;
using std::stack;

const int MAX = 1e4 + 5;

struct Edge
{
	int x, y;
};

int cnt, n, m, sum, ans, a, b;
stack <int> s;
vector <int> e[MAX];
vector <Edge> g;
int dfn[MAX], low[MAX], v[MAX], w[MAX], bl[MAX], f[MAX];
bool in[MAX];

void dfs(int x)
{
	++cnt;
	dfn[x] = low[x] = cnt;
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
		else if(in[y])
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
			v[sum] += w[s.top()];
			bl[s.top()] = sum; 
			s.pop();
		}
		in[x] = false;
		v[sum] += w[x];
		bl[x] = sum;
		s.pop();
	}
	return ;
}

void dfs2(int x)
{
	if (f[x])
	{
		return ;
	}
	const int len = e[x].size();
	int mx = 0;
	f[x] = v[x];
	for (int i = 0; i < len; ++i)
	{
		int y = e[x].at(i);
		dfs2(y);
		mx = std::max(mx, f[y]);
	}
	f[x] += mx;
	return ;
}
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> w[i];
	}

	for (int i = 1; i <= m; ++i)
	{
		cin >> a >> b;
		e[a].push_back(b);
		g.push_back(Edge{a, b});
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!dfn[i])
		{
			dfs(i);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		e[i].clear();
	}

	const int len = g.size();
	for (int i = 0; i < len; ++i)
	{
		if (bl[g.at(i).x] != bl[g.at(i).y])
		{
			e[bl[g.at(i).x]].push_back(bl[g.at(i).y]);
		}
	}

	for (int i = 1; i <= sum; ++i)
	{
		if (!f[i])
		{
			dfs2(i);
		}
	}

	for (int i = 1; i <= sum; ++i)
	{
		ans = std::max(ans, f[i]);
	}

	cout << ans;
	return 0;
}

