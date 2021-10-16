#include <iostream>

using std::cin;
using std::cout;

int main()
{
	long long n, p, k;
	cin >> n >> p >> k;
	cout << (p * k) % n;
	return 0;
}
