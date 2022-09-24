#include <iostream>

using std::cin;
using std::cout;

int n, m, p, u, v, father[50005];

void init()
{
	for (int i = 0; i <= 50005; ++i)
	{
		father[i] = i;
	}
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
	
	init();

	cin >> n >> m >> p;
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v;
		int fu = find(u), fv = find(v);
		if (fu != fv)
		{
			father[fv] = fu;
		}
	}

	for (int i = 1; i <= p; ++i)
	{
		cin >> u >> v;
		int fu = find(u), fv = find(v);
		if (fu == fv)
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	}

	return 0;
}


