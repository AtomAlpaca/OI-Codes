#include <iostream>

using std::cin;
using std::cout;

int p;
int ans[1005];

int main()
{
	int m;
	cin >> m;

	while (m)
	{
		ans[p] = (m + 1) / 2;
		m /= 2;
		++p;
	}

	cout << p << '\n';

	for (int i = p - 1; i >= 0; --i)
	{
		cout << ans[i] << ' ';
	}

	return 0;
}
