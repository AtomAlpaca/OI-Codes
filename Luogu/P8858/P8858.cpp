#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;

const int MAX = 5e5 + 5;

struct Point
{
	int x, y;
} p[MAX];

vector <int> a1[MAX], a2[MAX];

int T, n;

bool c2()
{
	int k1 = 0, k2 = 0;
	for (int i = 1; i <= n; ++i)
	{
		k1 += a1[i].size();
		k2 += a2[i].size();
		if (k1 == n / 2 or k2 == n / 2)
		{
			return true;
		}
		if (k1 > n / 2 and k2 > n / 2)
		{
			return false;
		}
	}

	return false;
}

bool c3()
{
	int k1 = 0, i, j, t = n, s = 0;
	for (i = 1; i <= n; ++i)
	{
		k1 += a1[i].size();
		if (k1 > n / 2)
		{
			i -= 1;
			break;
		}
	}

	for (j = i; j >= 1; --j)
	{
		s = 0;
		k1 -= a1[j + 1].size();
		for (t = n; t >= 1; --t)
		{
			if (a2[t].empty())
			{
				continue;
			}
			std::sort(a2[t].begin(), a2[t].end());

			const int len = a2[t].size();

			for (int q = len - 1; q >= 0; --q)
			{
				if (a2[t].at(q) <= j)
				{
					break;
				}
				++s;
			}
			
			if (k1 + s == n / 2)
			{
				return true;
			}

			if (k1 + s > n / 2)
			{
				break;
			}
		}
	}


	int k2 = 0;
	t = n, s = 0;

	for (i = 1; i <= n; ++i)
	{
		k2 += a2[i].size();
		if (k2 > n / 2)
		{
			i -= 1;
			break;
		}
	}

	for (j = i; j >= 1; --j)
	{
		s = 0;
		k2 -= a2[j + 1].size();
		for (t = n; t >= 1; --t)
		{
			if (a1[t].empty())
			{
				continue;
			}
			std::sort(a1[t].begin(), a1[t].end());

			const int len = a1[t].size();

			for (int q = len - 1; q >= 0; --q)
			{
				if (a1[t].at(q) <= j)
				{
					break;
				}
				++s;
			}
			
			if (k2 + s == n / 2)
			{
				return true;
			}

			if (k2 + s > n / 2)
			{
				break;
			}
		}
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			a1[i].clear();
			a2[i].clear();
		}
		for (int i = 1; i <= n; ++i)
		{
			cin >> p[i].x >> p[i].y;
			a1[p[i].x].push_back(p[i].y);
			a2[p[i].y].push_back(p[i].x);
		}

		if (c2())
		{
			cout << 2 << '\n';
		}
		else if(c3())
		{
			cout << 3 << '\n';
		}
		else
		{
			cout << 4 << '\n';
		}
	}
	return 0;
}
