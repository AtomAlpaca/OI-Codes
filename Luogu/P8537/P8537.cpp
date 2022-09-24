#include <iostream>

using std::cin;
using std::cout;

int n, a[500005], b[500005];
int ans, tmp;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> b[i];
		if (a[i] != b[i])
		{
			++ans;
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (a[i] != b[n - i + 1])
		{
			++tmp;
		}
	}

	ans = std::min(ans, tmp + 1);

	cout << ans;

	return 0;
}
