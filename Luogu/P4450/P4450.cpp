#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 1e6 + 5;

long long cnt, n, m, d;
long long ans;
long long mu[MAX], pri[MAX], s[MAX];
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

int main()
{
	init();
	cin >> m >> n >> d;
	m /= d, n /= d;
	int l = 1, r = 1;
	while (l <= std::min(m, n))
	{
		r = std::min(m / (m / l), n / (n / l));
		ans += (s[r] - s[l - 1]) * (m / l) * (n / l);
		l = r + 1;
	}

	cout << ans;
}

