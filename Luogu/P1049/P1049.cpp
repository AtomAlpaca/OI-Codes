#include <iostream>

using std::cin;
using std::cout;

int v, n, w[35], f[35][20000];

int main()
{
	cin >> v >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> w[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = v; j > 0; --j)
		{
			if (j >= w[i])
			{
				f[i][j] = std::max(f[i - 1][j], f[i - 1][j - w[i]] + w[i]);
			}
			else
			{
				f[i][j] = f[i - 1][j];
			}
		}
	}

	cout << v - f[n][v];
	return 0;
}
