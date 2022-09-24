#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 30005;

char op;
int T, u, v;
int father[MAX], dis[MAX], num[MAX], lax[MAX];

void init()
{
	for (int i = 0; i < MAX; ++i)
	{
		father[i] = i;
		num[i] = 1;
	}
	return ;
}

int find(int x)
{
	if (x == father[x])
	{
		return x;
	}
	int k = father[x];
	father[x] = find(father[x]);
	dis[x] += dis[k];
	num[x] = num[father[x]];
	return father[x];
}

void merge(int x, int y)
{
	int fx = find(x), fy = find(y);
	if (fx != fy)
	{
		father[fx] = fy;
		dis[fx] = num[fy] + dis[fy];
		num[fx] = num[fy] = num[fx] + num[fy];
	}
	return ;
}

int main()
{
	init();
	cin >> T;
	while (T--)
	{
		cin >> op >> u >> v;
		if (op == 'M')
		{
			merge(u, v);
		}
		else
		{
			int fu = find(u), fv = find(v);
			if (fu != fv)
			{
				cout << "-1\n";
			}
			else
			{
				cout << std::abs(dis[u] - dis[v]) - 1 << '\n';
			}
		}
	}
	return 0;
}

