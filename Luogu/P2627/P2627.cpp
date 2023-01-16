#include <iostream>

using std::cin;
using std::cout;

const int MAX = 1e5 + 5;

long long h = 1, t = 1, n, k;
long long e[MAX], s[MAX], q[MAX];
long long f[MAX][2];

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> e[i];
		s[i] = s[i - 1] + e[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		f[i][0] = std::max(f[i - 1][0], f[i - 1][1]);
		while (h <= t and q[h] < i - k)
		{
			++h;
		}
		f[i][1] = f[q[h]][0] + (s[i] - s[q[h]]);
		while (f[i][0] - s[i] > f[q[t]][0] - s[q[t]] and h <= t)
		{
			--t;
		}
		++t;
		q[t] = i;
	}

	cout << std::max(f[n][0], f[n][1]);
	return 0;
}
