#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;
const int MAX = 1e8 + 5;

struct Edge
{
	long long x, w;
};

long long ans, n, u, v, w, cnt = 1;
long long dis[100005];
vector <Edge> e[100005];
long long nxt[MAX][2];

void ins(long long x)
{
	int p = 1;
	for (int i = 30; i >= 0; --i)
	{
		int c = (bool)((x >> i) & 1);
		if (!nxt[p][c])
		{
			nxt[p][c] = ++cnt;
		}
		p = nxt[p][c];
	}
}

void get(long long x)
{
	int p = 1, sum = 0;
	for (int i = 30; i >= 0; --i)
	{
		int c = (bool)((x >> i) & 1);
		if (nxt[p][c ^ 1])
		{
			p = nxt[p][c ^ 1];
			sum |= (1 << i);
		}
		else
		{
			p = nxt[p][c];
		}
	}
	if (sum > ans)
	{
		ans = sum;
	}
}

void dfs(int x, int fa)
{
	const int len = e[x].size();
	ins(dis[x]);
	get(dis[x]);

	for (int i = 0; i < len; ++i)
	{
		int y = e[x].at(i).x;
		if (y == fa)
		{
			continue;
		}
		dis[y] = dis[x] ^ e[x].at(i).w;
		dfs(y, x);
	}
	return ;
}

int main()
{
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		cin >> u >> v >> w;
		e[u].push_back(Edge{v, w});
		e[v].push_back(Edge{u, w});
	}

	dfs(1, -1);
	
	cout << ans;
}

