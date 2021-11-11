#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;

struct Edge
{
	int u, v, w;
} edge[10005];

long long sum, ans;
int n, k, t;
int father[10005];

bool cmp(Edge edge1, Edge edge2)
{
	return edge1.w < edge2.w;
}

int find(int x)
{
	if (father[x] == x)
	{
		return father[x];
	}
	else
	{
		father[x] = find(father[x]);
		return father[x];
	}
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 10005; ++i)
	{
		father[i] = i;
	}

	cin >> n >> k;

	for (int i = 0; i < k; ++i)
	{
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
		sum += edge[i].w;
	}

	std::sort(edge, edge + k, cmp);

	for (int i = 0; i < k and t != n - 1; ++i)
	{
		int fatherU = find(edge[i].u);
		int fatherV = find(edge[i].v);
		if (fatherU != fatherV)
		{
			father[fatherV] = fatherU;
			sum -= edge[i].w;
			++k;
		}
	}

	cout << sum;
	return 0;
}