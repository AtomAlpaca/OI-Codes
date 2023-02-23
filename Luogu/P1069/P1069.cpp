#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;

const int MAX = 3e4 + 5;
const int INF = 0x3f3f3f3f;

int n, m1, m2, tmp, ans = INF, t, cnt;
int f[MAX], g[MAX], pri[MAX];

vector <int> p, q;

bool ip(int x)
{
	for (int i = 2; i * i <= x; ++i)
	{
		if (!(x % i))
		{
			return false;
		}
	}
	return true;
}

void init()
{
	pri[0] = 2;
	++cnt;
	for (int i = 3; i <= MAX; ++i)
	{
		if (ip(i))
		{
			pri[cnt] = i;
			++cnt;
		}
	}
	return ;
}

int main()
{
	init();
	cin >> n >> m1 >> m2;
	if (m1 == 1)
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; pri[i] and pri[i] <= m1; ++i)
	{
		if (!(m1 % pri[i]))
		{
			p.push_back(i);
			while (!(m1 % pri[i]))
			{
				m1 /= pri[i];
				f[i] += m2;
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		int mx = -1;
		cin >> t;
		for (int i = 0; i < MAX; ++i)
		{
			g[i] = 0;
		}
		for (int j = 0; pri[j] and pri[j] <= t; ++j)
		{
			if (!(t % pri[j]))
			{
				while (!(t % pri[j]))
				{
					t /= pri[j];
					++g[j];
				}
			}
		}

		for (int j : p)
		{
			if (!g[j])
			{
				mx = INF;
				break;
			}
			mx = std::max(mx, (int)std::ceil((double)f[j] / (double)g[j]));
		}
		ans = std::min(ans, mx);
	}
	if (ans == INF)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
}

