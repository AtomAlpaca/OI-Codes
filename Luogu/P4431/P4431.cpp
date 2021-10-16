#include <iostream>

using std::cin;
using std::cout;

int main()
{
	int k, n, m;
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> n >> m;
		cout << (std::min(n, m) - 1) * 2 << "\n";
	}
	return 0;
}
