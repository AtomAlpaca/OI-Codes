#include <iostream>

using std::cin;
using std::cout;

struct Node
{
	int x, y;
} a[205];

int n, ans;
int nums[105], f[205][205];

int main()
{
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> nums[i];
	}

	for (int i = 1; i < n; ++i)
	{
		a[i].x = nums[i];
		a[i].y = nums[i + 1];
	}

	a[n].x = nums[n];
	a[n].y = nums[1];

	for (int i = 1; i <= n; ++i)
	{
		a[i + n] = a[i];
	}

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j + i - 1 <= 2 * n; ++j)
		{
			for (int k = j; k < j + i - 1; ++k)
			{
				f[j][j + i - 1] = std::max(f[j][j + i - 1], 
										   f[j][k] + f[k + 1][j + i - 1] + a[j].x * a[k].y * a[i + j - 1].y);
			}
		}
	}

	for (int i = 1; i + n <= 2 * n; ++i)
	{
		ans = std::max(ans, f[i][i + n - 1]);
	}

	cout << ans;
}
