#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;
using std::pair;

int s, n, m, k, f[20005], ans = -1;
vector <pair <int, int>> a[105]; /*cost, value*/

bool cmp(pair <int, int> p1, pair <int, int> p2)
{
	if (p1.first == p2.first)
	{
		return p1.second > p2.second;
	}
	return p1.first < p2.first;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> s >> n >> m;

	for (int i = 1; i <= s; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> k;
			pair <int, int> o = {k * 2 + 1, j};
			a[j].push_back(o);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		std::sort(a[i].begin(), a[i].end(), cmp);
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = m; j >= a[i].at(0).first; --j)
		{
			for (int l = 0; l < s; ++l)
			{
				if (j < a[i].at(l).first)
				{
					break;
				}
				f[j] = std::max(f[j], f[j - a[i].at(l).first] + (a[i].at(l).second * (l + 1)));
			}
		}
	}


	for (int i = 0; i <= m; ++i)
	{
		ans = std::max(ans, f[i]);
	}

	cout << ans;
	return 0;
}

