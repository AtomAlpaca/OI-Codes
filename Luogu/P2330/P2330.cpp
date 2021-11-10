#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;

struct Edge
{
	int u, v, w;
} edge[100005];

long long n, m, ans, t;
int father[100005];

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
	else
	{
		father[x] = find(father[x]);
		return father[x];
	}
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i <= 100005; ++i)
	{
		father[i] = i;
	}

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}

	std::sort(edge, edge + m, cmp);

	for (int i = 0; i < m and t != n - 1; ++i)
	{
		int fatherU = find(edge[i].u);
		int fatherV = find(edge[i].v);

		if (fatherU != fatherV)
		{
			father[fatherV] = fatherU;
			ans = edge[i].w;
			++t;
		}
	}

	cout << n - 1 << ' ' << ans;
	return 0;
}