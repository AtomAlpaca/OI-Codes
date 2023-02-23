#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 1e3 + 5;

struct P
{
	long long x, y, z;
} a[MAX];

bool vis[MAX];
long long T, n;
long long h, r;

// 4 * 2 * 2 <= 2 * 2 + 2 * 2

bool check(P p1, P p2, long long r)
{
	return 4 * r * r >= (p1.x - p2.x) * (p1.x - p2.x) 
				      + (p1.y - p2.y) * (p1.y - p2.y)
					  + (p1.z - p2.z) * (p1.z - p2.z);
}

bool cmp(P p1, P p2)
{
	return p1.z < p2.z;
}

long long as(long long x)
{
	if (x >= 0)
	{
		return x;
	}
	return -x;
}

void dfs(int x)
{
	for (int i = 1; i <= n; ++i)
	{
		if (vis[i] or as(a[i].z - a[x].z) > 2 * r or i == x)
		{
			continue;
		}
		if (check(a[i], a[x], r))
		{
			vis[i] = true;
			dfs(i);
		}
	}
}

int main()
{
/*	freopen("cheese.in",  "r", stdin);
	freopen("cheese.out", "w", stdout);*/
	cin >> T;
	while (T--)
	{
		cin >> n >> h >> r;
		for (int i = 1; i <= n; ++i)
		{
			vis[i] = false;
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		if (n == 1)
		{
			if (a[1].z + r >= h and a[1].z <= r)
			{
				cout << "Yes\n";
			}
			else
			{
				cout << "No\n";
			}
			continue;
		}
		std::sort(a + 1, a + n + 1, cmp);
		if (a[1].z > r or a[n].z + r < h)
		{
			cout << "No\n";
			continue;
		}

		for (int i = 1; i <= n; ++i)
		{
			if (a[i].z > r)
			{
				break;
			}
			vis[i] = true;
			dfs(i);
		}
		for (int i = n; i >= 1; --i)
		{
			if (vis[i] and a[i].z + r >= h)
			{
				cout << "Yes\n";
				break;
			}
			if (a[i].z + r < h or i == 1)
			{
				cout << "No\n";
				break;
			}
		}
	}
	return 0;
}

