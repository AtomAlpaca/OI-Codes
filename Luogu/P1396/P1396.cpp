#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;

int n, m, s, t;
int father[10005];

struct Edge
{
	int u, v, cost;
} edge[20005];

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

bool cmp(Edge edge1, Edge edge2)
{
	return edge1.cost < edge2.cost;
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i <= 20005; ++i)
	{
		father[i] = i;
	}

	cin >> n >> m >> s >> t;

	for (int i = 0; i < m; ++i)
	{
		cin >> edge[i].u >> edge[i].v >> edge[i].cost;
	}


	std::sort(edge, edge + m, cmp);



	for (int i = 0; i < m; ++i)
	{
		int fatherU = find(edge[i].u);
		int fatherV = find(edge[i].v);
		if (fatherU != fatherV)
		{
			father[fatherU] = father[fatherV];
		}
		if (find(s) == find(t))
		{
			cout << edge[i].cost;
			break;
		}
	}

	return 0;
}