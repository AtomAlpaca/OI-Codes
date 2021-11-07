#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;

struct Edge
{
	int u, v;
} edge[10005];

int n, m, t;
int father[10005];

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

void init()
{
	t = 0;
	for (int i = 0; i < 10005; ++i)
	{
		father[i] = i;
	}
}

int main(int argc, char const *argv[])
{
	while (true)
	{
		init();
		cin >> n;
		if (n == 0)
		{
			break;
		}
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			cin >> edge[i].u >> edge[i].v;
			int fatherU = find(edge[i].u);
			int fatherV = find(edge[i].v);
			if (fatherU != fatherV)
			{
				++t;
				father[fatherV] = fatherU;
			}
		}
		if (t >= n - 1)
		{
			cout << 0 << '\n';
		}
		else
		{
			cout << n - 1 - t << '\n';
		}
	}
	return 0;
}