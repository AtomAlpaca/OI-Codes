#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;

struct Edge
{
	int u, v, cost;
} edge[10005];

int ans, n, num, k;
int father[105];

bool cmp(Edge edge1, Edge edge2)
{
	return edge1.cost < edge2.cost;
}

int find(int x)
{
	if (father[x] == x)
	{
		return x;
	}
	else
	{
		return x = find(father[x]);
	}
}

int main()
{
	for (int i = 0; i < 105; ++i)
	{
		father[i] = i;
	}
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int tmp;
			cin >> tmp;
			if (i > j)
			{
				edge[num].cost = tmp;
				edge[num].u = i;
				edge[num].v = j;
				++num;
			}
		}
	}

	std::sort(edge, edge + num, cmp);

	for (int i = 0; i < num; ++i)
	{
		int fatherU = find(edge[i].u);
		int fatherV = find(edge[i].v);
		if (fatherU != fatherV)
		{
			++k;
			ans += edge[i].cost;
			father[fatherU] = fatherV;
		}
		if (k == n - 1)
		{
			break;
		}
	}

	cout << ans;
	return 0;
}
