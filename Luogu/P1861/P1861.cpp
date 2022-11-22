#include <iostream>

using std::cin;
using std::cout;

long long n, m, s, e, t;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> t;
			s += t * (i * i + j * j);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> t;
			e += t * (i * i + j * j);
		}
	}

	cout << (s - e) / 2;
}
