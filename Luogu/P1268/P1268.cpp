#include <iostream>

using std::cin;
using std::cout;

const int MAX = 35;

int u, v, w = -1, n;
int m[MAX][MAX];

int main()
{
	while (true)
	{
		cin >> n;
		if (n == 0)
		{
			break;
		}
		for (int i = n - 1; i >= 1; --i)
		{
			for (int j = 1; j <= i; ++j)
			{
				cin >> m[n - i][j + n - i];
				m[j + n - i][n - i] = m[n - i][j + n - i];
			}
		}

		long long ans = m[1][2];
		int cur = 0;
	
		for (int i = 3; i <= n; ++i)
		{
			cur = 0x3f3f3f3f;
			for (int j = 1; j < i; ++j)
			{
				for (int k = j + 1; k <= i; ++k)
				{
					if (k == j or k == i or j == i)
					{
						continue;
					}
					cur = std::min(cur, (m[i][j] + m[i][k] - m[j][k]) / 2);
				}
			}
			ans += cur;
		}

		cout << ans << '\n';
	}
	return 0;
}
