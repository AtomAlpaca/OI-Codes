#include <iostream>

using std::cin;
using std::cout;

int T, n, m;

int main(int argc, char const *argv[])
{
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		if (n == m)
		{
			cout << 0;
		}
		else if (n % 2 == 1 and m % 2 == 0 and n < m)
		{
			cout << 1;
		}
		else if (n % 2 == 1 and m % 2 == 0 and n > m)
		{
			cout << 2;
		}
		else if (n % 2 == 0 and m % 2 == 0 and n < m)
		{
			cout << 2;
		}
		else if (n % 2 == 0 and m % 2 == 0 and n > m)
		{
			cout << 1;
		}

		else if (n % 2 == 1 and m % 2 == 1 and n < m)
		{
			cout << 2;
		}
		else if (n % 2 == 1 and m % 2 == 1 and n > m)
		{
			cout << 1;
		}
		else if (n % 2 == 0 and m % 2 == 1 and n < m)
		{
			cout << 1;
		}
		else if (n % 2 == 0 and m % 2 == 1 and n > m)
		{
			cout << 2;
		}
		cout << '\n';
	}
	return 0;
}
