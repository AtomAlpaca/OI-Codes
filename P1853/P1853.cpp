#include <iostream>

using std::cin;
using std::cout;

long long s, n, d, c[15], v[15], f[4000005], ans = -1;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> s >> n >> d;
	for (int i = 1; i <= d; ++i)
	{
		cin >> c[i] >> v[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		ans = -1;
		for (int j = 1; j <= d; ++j)
		{
			for (int k = c[j]; k <= s; ++k)
			{
				f[k] = std::max(f[k], f[k - c[j]] + v[j]);
			}
		}

		for (int j = 0; j <= s; ++j)
		{
			ans = std::max(ans, f[j]);
		}
		for (int j = 0; j <= s; ++j)
		{
			f[j] = 0;
		}
		s += ans;
	}

	cout << s;

	return 0;
}

