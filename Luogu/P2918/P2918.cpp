#include <iostream>

using std::cin;
using std::cout;

int h, n, v[105], c[105], f[100005], ans;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> h;

	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i] >> c[i];
	}

	for (int i = 1; i <= 100005; ++i)
	{
		f[i] = 0x3f3f3f3f;
	}
	ans = 0x3f3f3f3f;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = v[i]; j <= 100005; ++j)
		{
			f[j] = std::min(f[j], f[j - v[i]] + c[i]);
		}
	}

	for (int i = h; i <= 100005; ++i)
	{
		ans = std::min(ans, f[i]);
	}

	cout << ans;
	return 0;
}
