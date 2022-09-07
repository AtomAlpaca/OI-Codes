#include <iostream>

using std::cin;
using std::cout;

const int MOD = 1e6 + 7;
int n, m;
int a[105], f[105];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	f[0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = m; j >= 1; --j)
		{
			for (int k = 1; k <= a[i] && j - k >= 0; ++k)
			{
				f[j] = f[j - k] + f[j];
				f[j] %= MOD;
			}
		}
	}

	cout << f[m] % MOD;
}
