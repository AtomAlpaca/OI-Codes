#include <iostream>

using std::cin;
using std::cout;

long long T, n, sum, xr, tmp;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;
	while (T--)
	{
		sum = xr = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> tmp;
			sum += tmp;
			xr  ^= tmp;
		}

		cout << 2 << '\n';
		cout << xr << ' ' << xr + sum << '\n';
	}
	return 0;
}
