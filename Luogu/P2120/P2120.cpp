#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 1e6 + 5;
const int INF = 0x3f3f3f3f;

long long n, t, h;
long long ans = INF;
long long c[MAX], d[MAX], x[MAX], f[MAX];
long long a[MAX], b[MAX];
int q[MAX];

double sl(long long x, long long y)
{
	if (a[x] == a[y])
	{
		return INF;
	}
	return (double)(f[x] + b[x] - f[y] - b[y]) / (double)(a[x] - a[y]);
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> d[i] >> x[i] >> c[i];
		a[i] = a[i - 1] + x[i];
		b[i] = b[i - 1] + x[i] * d[i];
	}

	t = h = 1;

	for (int i = 1; i <= n; ++i)
	{
		while (t > h and d[i] > sl(q[h], q[h + 1]))
		{
			++h;
		}
		f[i] = f[q[h]] + d[i] * (a[i] - a[q[h]]) - (b[i] - b[q[h]]) + c[i];
		while (t > h and sl(q[t - 1], i) < sl(q[t - 1], q[t]))
		{
			--t;
		}
		++t;
		q[t] = i;
	}

	ans = f[n];

	for (int i = n; i >= 1; --i)
	{
		ans = std::min(ans, f[i]);
		if (x[i])
		{
			break;
		}
	}

	cout << ans;
	return 0;
}
