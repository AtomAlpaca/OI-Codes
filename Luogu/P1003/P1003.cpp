#include <iostream>

using std::cin;
using std::cout;

int main()
{
	int n, a[100005], b[100005], g[100005], k[100005], x, y;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i] >> b[i] >> g[i] >> k[i];
	}

	cin >> x >> y;

	for (int i = n - 1; i >= 0; --i)
	{
		if (x >= a[i] and x <= a[i] + g[i] and y >= b[i] and y <= b[i] + k[i]) 
		{
			cout << i + 1;
			return 0;
		}
	}

	cout << -1;
	return 0;
}
