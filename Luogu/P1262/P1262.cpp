#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::stack;
using std::vector;

const int MAX = 3e3 + 5;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int x, y;
};

bool flag;
int cnt, sum, val, ans = INF, o, r, t, n, m;
vector <int> e[MAX], b[MAX];
vector <Edge> g;
stack <int> s;
int dfn[MAX], low[MAX], d[MAX], id[MAX], bl[MAX], v[MAX], w[MAX];
bool in[MAX];

void dfs(int x)
{
	low[x] = dfn[x] = ++cnt;
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
			b[sum].push_back(p);
			v[sum] = std::min(v[sum], w[p]);
			bl[p] = sum;
			if (w[p] == INF)
			{
				id[sum] = std::min(id[sum], p);
			}
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
	for (int i = 1; i <= n; ++i)
	{
		id[i] = v[i] = w[i] = INF;
	}
	for (int i = 1; i <= m; ++i)
	{
		cin >> r >> t;
		w[r] = t;
	}

	cin >> o;
	for (int i = 1; i <= o; ++i)
	{
		cin >> r >> t;
		e[r].push_back(t);
		g.push_back(Edge{r, t});
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
		int x = g[i].x, y = g[i].y;
		if (bl[x] != bl[y])
		{
			++d[bl[y]];
		}
	}

	for (int i = 1; i <= sum; ++i)
	{
		if (d[i] == 0)
		{
			if (v[i] == INF)
			{
				flag = true;
				ans = std::min(ans, id[i]);
			}
			else
			{
				val += v[i];
			}
		}
	}

	if (flag)
	{
		cout << "NO\n" << ans;
	}
	else
	{
		cout << "YES\n" << val;
	}
}

