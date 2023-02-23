#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 5e4 + 5;

long long a, b, d, cnt, l, r, ans, T;
bool vis[MAX];
long long s[MAX], mu[MAX], pri[MAX];

long long R(long long n, long long x)
{
	return n / (n / x);
}

void init()
{
	mu[1] = 1;
	for (int i = 2; i < MAX - 3; ++i)
	{
		if (!vis[i])
		{
			++cnt;
			pri[cnt] = i;
			mu[i] = -1;
		}
		for (int j = 1; j <= cnt and pri[j] * i < MAX; ++j)
		{
			vis[pri[j] * i] = true;
			if (i % pri[j] == 0)
			{
				break;
			}
			mu[pri[j] * i] = -mu[i];
		}
	}

	for (int i = 1; i < MAX - 3; ++i)
	{
		s[i] = s[i - 1] + mu[i];
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	init();
	cin >> T;
	while (T--)
	{
		ans = 0;
		cin >> a >> b >> d;
		a /= d;
		b /= d;
		
		l = 1;
		while (l <= std::min(a, b))
		{
			r = std::min(a / (a / l), b / (b / l));
			ans += (s[r] - s[l - 1]) * (a / l) * (b / l);
			l = r + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}

