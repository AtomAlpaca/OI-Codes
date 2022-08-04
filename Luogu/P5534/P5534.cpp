#include <iostream>

using std::cin;
using std::cout;

long long a1, a2, d, an, n;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> a1 >> a2 >> n;
	d = a2 - a1;
	an = a1 + ((n - 1) * d);

	cout << (a1 + an) * n / 2;

	return 0;
}
