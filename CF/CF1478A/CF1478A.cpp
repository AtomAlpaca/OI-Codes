#include <iostream>

using std::cin;
using std::cout;

int T, mx, tim, a, b, n;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		tim = mx = 1;
		cin >> n >> b;
		for (int i = 2; i <= n; ++i)
		{
			cin >> a;
			if (a == b)
			{
				++tim;
			}
			else
			{
				mx = std::max(mx, tim);
				tim = 1;
			}
			b = a;
		}

		cout << std::max(mx, tim) << '\n';
	}

	return 0;
}
