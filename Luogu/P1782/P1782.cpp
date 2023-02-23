#include <iostream>

using std::cin;
using std::cout;

const int MAX = 2e5 + 5;

int n, m, o, p, d, cnt, a1[9], a2[9], a3[9], ans, c;
int w[MAX], v[MAX], f[MAX];

void init1(int o, int p, int d)
{
	int k = 1;
	while (true)
	{
		if (d <= k)
		{
			++cnt;
			v[cnt] = o * k;
			w[cnt] = p * k;
			d -= k;
		}
		else
		{
			++cnt;
			v[cnt] = o * d;
			w[cnt] = p * d;
			break;
		}
		k <<= 1;
	}
}

int main()
{
	cin >> n >> m >> c;
	for (int i = 1; i <= n; ++i)
	{
		cin >> o >> p >> d;
		init1(o, p, d);
	}

	for (int i = 1; i <= m; ++i)
	{
		cin >> a1[i] >> a2[i] >> a3[i];
	}

	for (int i = 1; i <= cnt; ++i)
	{
		for (int j = c; j >= v[i]; --j)
		{
			f[j] = std::max(f[j], f[j - v[i]] + w[i]);
		}
	}

	for (int i = 1; i <= m; ++i)
	{
		for (int j = c; j >= 0; --j)
		{
			for (int k = 0; k <= j; ++k)
			{
				if (k == 0 and a1[i] * k * k + a2[i] * k + a3[i] < 0)
				{
					continue;
				}
				f[j] = std::max(f[j], f[j - k] + (a1[i] * k * k + a2[i] * k + a3[i]));
			}
		}
	}

	for (int i = 0; i <= c; ++i)
	{
		ans = std::max(f[i], ans);
	}

	cout << ans;
	return 0;
}
