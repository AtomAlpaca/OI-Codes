#include <iostream>

using std::cin;
using std::cout;

long long ans = -1, n, k, a[1000005], f[1000005];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> k;
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		f[i] = f[i - 1] + a[i];
	}

	for (int i = k + 1; i <= n; ++i)
	{
		ans = std::max(ans, f[i] - f[i - k - 1]);
	}

	cout << ans;
	return 0;
}

