#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 5e4 + 5;

int cnt, a, b, c, d, k, n;
int mu[MAX], pri[MAX], s[MAX];
bool vis[MAX];
void init()
{
	s[1] = mu[1] = 1;
	for (int i = 2; i < MAX; ++i)
	{
		if (!vis[i])
		{
			pri[++cnt] = i;
			mu[i] = -1;
		}
		vis[i] = true;
		for (int j = 1; j <= cnt and pri[j] * i < MAX; ++j)
		{
			if (i % pri[j] == 0)
			{
				mu[i * pri[j]] = 0;
			}
			else
			{
				mu[i * pri[j]] = -mu[i];
			}
			vis[i * pri[j]] = true;
		}
	}

	for (int i = 1; i < MAX; ++i)
	{
		s[i] = s[i - 1] + mu[i];
	}
	return ;
}

int f(int m, int n, int d)
{
	int ans = 0;
	m /= d, n /= d;
	int l = 1, r = 1;
	while (l <= std::min(m, n))
	{
		r = std::min(n / (n / l), m / (m / l));
		ans += (s[r] - s[l - 1]) * (n / l) * (m / l);
		l = r + 1;
	}
	return ans;
}

int main()
{
	init();
	cin >> n;
	while (n--)
	{
		cin >> a >> b >> c >> d >> k;
		cout << f(b, d, k) - f(a - 1, d, k) - f(b, c - 1, k) + f(a - 1, c - 1, k) << '\n';
	}
	return 0;
}

