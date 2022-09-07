#include <iostream>

using std::cin;
using std::cout;

long long t, a;

bool sol(long long x)
{
	while (x % 2 == 0)
	{
		x /= 2;
	}
	return !(x == 1);
}

int main()
{
	cin >> t;

	for (int i = 1; i <= t; ++i)
	{
		cin >> a;
		if (sol(a))
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}
