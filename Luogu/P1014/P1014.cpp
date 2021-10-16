#include <iostream>

using std::cout;
using std::cin;

int main()
{
	int n;
	cin >> n;

	int p = 1;

	while (p < n)
	{
		n -= p;
		++p;
	}

	++p;

	if (p % 2 == 0)
	{
		cout << p - n << '/' << n;
	}
	else 
	{
		cout << n << '/' << p - n;
	}
	return 0;
}
