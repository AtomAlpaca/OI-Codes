#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;

struct Edge
{
	int u, v, w;
} edge[250005];

int A, B, now, wei, ans;
int father[505];

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
		return father[x] = find(father[x]);
	}

}

int main()
{
	for (int i = 0; i < 505; ++i)
	{
		father[i] = i;
	}

	cin >> A >> B;

	for (int i = 1; i <= B; ++i)
	{
		for (int j = 1; j <= B; ++j)
		{
			cin >> wei;
			if (i < j and wei) 
			{
				edge[now].u = i;
				edge[now].v = j;
				edge[now].w = wei;
				++now;
			}
		}
	}

	for (int i = 1; i <= B; ++i)
	{
		edge[now].u = 0;
		edge[now].v = i;
		edge[now].w = A;
		++now;
	}
	
	std::sort(edge, edge + now, cmp);

	for (int i = 0; i < now; ++i)
	{
		int fatherU = find(edge[i].u);
		int fatherV = find(edge[i].v);
		if (fatherU != fatherV)
		{
			father[fatherV] = fatherU;
			ans += edge[i].w;
		}
	}

	cout << ans;
	return 0;
}
