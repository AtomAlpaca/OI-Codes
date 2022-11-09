#include <iostream>

using std::cin;
using std::cout;

long long m = 1e9;
long long a, b, cnt;
long long ans = 1;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> a >> b;

	if (a == 1)
	{
		cout << 1;
		return 0;
	}

	while (m)
	{
		++cnt;
		m /= a;
	}

	if (cnt <= b)
	{
		cout << -1;
	}
	else
	{
		for (int i = 1; i <= b; ++i)
		{
			ans *= a;
		}
		cout << ans;
	}
	return 0;
}

