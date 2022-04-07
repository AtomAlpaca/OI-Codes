#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;

long long n, m, k, ans;
int father[200005];

struct Edge
{
	int u, v, w;
} edge[500005];

bool cmp(Edge edge1, Edge edge2)
{
	return edge1.w < edge2.w;
}

int find(int x)
{
	if (father[x] == x)
	{
		return x;
	}
	return father[x] = find(father[x]);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;
	
	for (int i = 0; i <= n; ++i)
	{
		father[i] = i;
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}

	std::sort(edge, edge + m, cmp);

	for (int i = 0; i < m and k != n - 1; ++i)
	{
		int fu = find(edge[i].u);
		int fv = find(edge[i].v);
		if (fu != fv)
		{
			father[fv] = fu;
			ans += edge[i].w;
			++k;
		}
	}

	cout << ans;
	return 0;
}
