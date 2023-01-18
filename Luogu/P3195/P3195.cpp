#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 5e4 + 5;

int n, L, h, t;
long long s[MAX], q[MAX], f[MAX], a[MAX], b[MAX];

double sl(int x, int y)
{
	return (double)(f[y] + b[y] * b[y] - f[x] - b[x] * b[x]) / (double)(b[y] - b[x]);
}

int main()
{
	cin >> n >> L;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s[i];
		s[i] += s[i - 1];
		a[i] = s[i] + i;
		b[i] = s[i] + i + L + 1;
	}
	a[0] = 0;
	b[0] = L + 1;
	h = 1, t = 1;
	for (int i = 1; i <= n; ++i)
	{
		while (h < t and 2 * a[i] > sl(q[h], q[h + 1]))
		{
			++h;
		}
		f[i] = f[q[h]] + (a[i] - b[q[h]]) * (a[i] - b[q[h]]);
		while (h < t and sl(q[t - 1], q[t]) > sl(q[t - 1], i))
		{
			--t;
		}
		++t;
		q[t] = i;
	}
	cout << f[n];
}
