#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 1e6 + 5;

long long a, b, c, n, h, t;
long long s[MAX], f[MAX], q[MAX];

double sl(long long x, long long y)
{
	return (double)(f[x] + a * s[x] * s[x] - b * s[x] - f[y] - a * s[y] * s[y] + b * s[y]) / (double)(s[x] - s[y]);
}

int main()
{
	cin >> n >> a >> b >> c;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s[i];
		s[i] += s[i - 1];
	}

	t = h = 1;

	for (int i = 1; i <= n; ++i)
	{
		while (t > h and sl(q[h], q[h + 1]) > 2 * a * s[i])
		{
			++h;
		}
		f[i] = f[q[h]] + a * (s[i] - s[q[h]]) * (s[i] - s[q[h]]) + b * (s[i] - s[q[h]]) + c;
		while (t > h and sl(q[t - 1], i) > sl(q[t - 1], q[t]))
		{
			--t;
		}
		++t;
		q[t] = i;
	}

	cout << f[n];
	return 0;
}
