#include <iostream>

using std::cin;
using std::cout;

char op;
int u, v, ans, n, m;
int father[2005];
bool fl[1005];

void init()
{
	for (int i = 0; i <= 2005; ++i)
	{
		father[i] = i;
	}
	return ;
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

	cin >> n >> m;

	for (int i = 1; i <= m; ++i)
	{
		cin >> op >> u >> v;
		int fu = find(u), fv = find(v);
		if (op == 'E')
		{
			father[find(n + v)] = fu;
			father[find(n + u)] = fv;
		}
		else
		{
			father[fv] = fu;
		}

	}

	for (int i = 1; i <= n; ++i)
	{
		int fi = find(i);
		if (!fl[fi])
		{
			++ans;
			fl[fi] = true;
		}
	}

	cout << ans;

	return 0;
}


