#include <cmath>
#include <iostream>

using std::cin;
using std::cout;

const int INF = 0x3f3f3f;

int T, n, a[200005], tmp = -INF;
long long ans;

void solve()
{
	ans = 0;
	tmp = -INF;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n - 1; ++i)
	{
		ans += std::abs(a[i + 1] - a[i]);
	}

	for (int i = 1; i < n - 1; ++i)
	{
		tmp = std::max(tmp, 
			  std::abs(a[i - 1] - a[i]) 
			+ std::abs(a[i + 1] - a[i]) 
			- std::abs(a[i + 1] - a[i - 1]));
	}

	tmp = std::max(tmp, std::abs(a[1] - a[0]));
	tmp = std::max(tmp, std::abs(a[n - 1] - a[n - 2]));

	ans -= tmp;
	cout << ans << '\n';
	return ;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}
