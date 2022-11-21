#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 1e5 + 5;

int n, m;
int a[MAX];
double mi, ma;

bool cmp(int x, int y)
{
	return x < y;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	std::sort(a + 1, a + n + 1, cmp);

	mi = ma = m;

	for (int i = 2; i <= n; ++i)
	{
		if (mi / (i - 1) <= a[i])
		{
			mi += m;
		}
	}

	for (int i = n - 1; i >= 1; --i)
	{
		if (ma / (n - i) <= a[i])
		{
			ma += m;
		}
	}

	cout << std::fixed << std::setprecision(2) << mi / n << ' ' << ma / n;
	return 0;
}
