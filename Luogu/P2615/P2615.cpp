#include <iostream>

using std::cout;
using std::cin;

int nums[40][40];

int main()
{
	int n;
	cin >> n;
	
	
	int x = 1, y = n / 2 + 1, MAX = n * n;

	for (int i = 1; i <= MAX; ++i)
	{
		nums[x][y] = i;

		if (i % n == 0)
		{
			++x;

			if (x > n)
			{
				x = 1;
			}
		}
		else
		{
			--x;
			if (x < 1)
			{
				x = n;
			}

			++y;
			if (y > n)
			{
				y = 1;
			}
		}

	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << nums[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
