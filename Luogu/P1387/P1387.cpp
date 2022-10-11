#include <iostream>

using std::cin;
using std::cout;

int n, m, k;
int a[105][105], sum[105][105];

bool judge(int l, int x, int y)
{
	for (int i = 0; i < l; ++i)
	{
		if (sum[x + i][y + l - 1] - sum[x + i][y - 1] != l)
		{
			return false;
		}
	}

	return true;
}

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
			cin >> a[i][j];
			sum[i][j] = sum[i][j - 1] + a[i][j];
		}
	}

	for (k = std::min(n, m); k >= 1; --k)
	{
		for (int i = 1; i + k - 1 <= n; ++i)
		{
			for (int j = 1; j + k - 1 <= m; ++j)
			{
				if (judge(k, i, j))
				{
					cout << k;
					return 0;
				}
			}
		}
	}

}
