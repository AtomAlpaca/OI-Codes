#include <iostream>

using std::cin;
using std::cout;

long long ans;
int m, n, u, v, op;
int father[4000005];

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

	while (m--)
	{
		cin >> op >> u >> v;
		int fu = find(u);
		int fv = find(v);
		if (op == 0)
		{
			if (fu != fv)
			{
				father[fv] = fu;
			}
		}
		else
		{
			ans <<= 1;
			if (fu == fv)
			{
				++ans;
			}
			ans %= 998244353;
		}
	}

	cout << ans % 998244353;

	return 0;
}
