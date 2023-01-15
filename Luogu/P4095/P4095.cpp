#include <iostream>

using std::cin;
using std::cout;

const int MAX = 1e3 + 5;

int n, a, b, c, d, e, ans, cnt, q;
int t[MAX], v[MAX * 10], w[MAX * 10];
int f[MAX * 10][MAX], g[MAX * 10][MAX];

void init(int x, int a, int b, int c)
{
	t[x] = cnt + 1;
	int k = 1;
	while (true)
	{
		if (c > k)
		{
			++cnt;
			v[cnt] = a * k;
			w[cnt] = b * k;
			c -= k;
			k <<= 1;
		}
		else
		{
			++cnt;
			v[cnt] = a * c;
			w[cnt] = b * c;
			break;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a >> b >> c;
		init(i, a, b, c);
	}

	for (int i = 1; i <= cnt; ++i)
	{
		for (int j = 1000; j >= 0; --j)
		{
			f[i][j] = f[i - 1][j];
		}
		for (int j = 1000; j >= v[i]; --j)
		{
			f[i][j] = std::max(f[i][j], f[i - 1][j - v[i]] + w[i]);
		}
	}

	for (int i = cnt; i >= 1; --i)
	{
		for (int j = 1000; j >= 0; --j)
		{
			g[i][j] = g[i + 1][j];
		}
		for (int j = 1000; j >= v[i]; --j)
		{
			g[i][j] = std::max(g[i][j], g[i + 1][j - v[i]] + w[i]);
		}
	}

	cin >> q;
	while (q--)
	{
		cin >> d >> e;
		++d;
		if (d == n)
		{
			cout << f[t[d] - 1][e] << '\n';
			continue;
		}
		if (d == 1)
		{
			cout << g[t[2]][e] << '\n';
			continue;
		}
		ans = 0;
		for (int k = 0; k <= e; ++k)
		{
			ans = std::max(ans, f[t[d] - 1][k] + g[t[d + 1]][e - k]);
		}
		cout << ans << "\n";
	}
	return 0;
}
