#include <iostream>

using std::cin;
using std::cout;

const int INF = 0x3f3f3f3f;

long long m, n;
long long a[205][205], f[205][205];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> m >> n;

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> a[i][j];
		}
	}

	const int p = (n - 1) >> 1;

	for (int i = 1, j = p - 1; i <= p; ++i, --j)
	{
		for (int k = 0; k < j; ++k)
		{
			a[m - i + 1][n - k] = a[m - i + 1][k + 1] = -INF;
		}
	}

	for (int i = m; i >= 1; --i)
	{
		for (int j = n; j >= 1; --j)
		{
			f[i][j] = a[i][j] + std::max(std::max(f[i + 1][j], f[i + 1][j - 1]), f[i + 1][j + 1]);
		}
	}

	long long ans = -INF;

	for (int i = 1; i <= n; ++i)
	{
		ans = std::max(ans, f[1][i]);
	}

	cout << ans;
	return 0;
}
