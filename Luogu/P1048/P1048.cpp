#include <iostream>

using std::cin;
using std::cout;

int t, m, w[1005], c[1005], f[1005][1005];

int main()
{
	cin >> t >> m;

	for (int i = 1; i <= m; ++i)
	{
		cin >> w[i] >> c[i];
	}

	for (int i = 1; i <= m; ++i)
	{
		for (int v = t; v >= 0; --v)
		{
			if (v >= w[i])
			{
				f[i][v] = std::max(f[i - 1][v], f[i - 1][v - w[i]] + c[i]);
			}
			else
			{
				f[i][v] = f[i - 1][v];
			}
		}
	}

	cout << f[m][t];

	return 0;
}
