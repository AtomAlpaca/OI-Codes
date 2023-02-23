#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 2e5 + 5;
const int INF = 0x3f3f3f3f;

long long T, n, ans, mn = INF, t, cnt;

void solve()
{
	ans = 0; mn = INF, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> t;
		if (t < 0)
		{
			cnt ^= 1;
		}

		ans += std::abs(t);
		mn = std::min(mn, std::abs(t));
	}
	if (cnt)
	{
		cout << ans - 2 * mn;
	}
	else
	{
		cout << ans;
	}
	cout << '\n';
}

int main()
{
	cin >> T;
	while (T--)
	{
		solve();
	}
}

