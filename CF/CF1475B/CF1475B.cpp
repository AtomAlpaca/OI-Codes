#include <iostream>

using std::cin;
using std::cout;

int t, n;

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n % 2020 <= n / 2020)
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
