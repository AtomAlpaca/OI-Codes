#include <algorithm>
#include <cmath>
#include <iostream>

using std::cin;
using std::cout;

int main()
{
	int x, y, ans = 0;
	cin >> x >> y;

	int k = x * y;
	int s = std::sqrt(k);

	for (int i = 1; i <= s; ++i)
	{
		if (k % i == 0 and std::__gcd(i, k / i) == x)
		{
			ans += 2;
		}
	}

	if (x == y)
	{
		--ans;
	}

	cout << ans;
	return 0;
}
