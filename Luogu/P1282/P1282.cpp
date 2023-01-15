#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int INF = 0x3f3f3f3f;
const int MAX = 1e3 + 5;

int sum, n, t, q;
int a[MAX], b[MAX], d[MAX], f[6005];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i];
		d[i] = b[i] - a[i];
		sum += (a[i] + b[i]);
		t += (a[i]);
		q += std::max(a[i], b[i]);
	}

	if (t == sum / 2)
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i <= 6004; ++i)
	{
		f[i] = INF;
	}
	f[t] = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (d[i] > 0)
		{
			for (int j = q; j >= sum - q; --j)
			{
				f[j] = std::min(f[j - d[i]] + 1, f[j]);
			}
		}
		else
		{
			for (int j = sum - q; j <= q; ++j)
			{
				f[j] = std::min(f[j - d[i]] + 1, f[j]);
			}
		}
	}

	int ans1 = INF, ans2 = INF;

	for (int i = 0; i <= q; ++i)
	{
		int d = std::abs((sum - i) - i);
		if (f[i] == INF)
		{
			continue;
		}
		if (d < ans1)
		{
			ans1 = d;
			ans2 = f[i];
		}
		else if(d == ans1)
		{
			ans2 = std::min(ans2, f[i]);
		}
	}

	cout << ans2;
}
