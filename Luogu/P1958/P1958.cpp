#include <algorithm>
#include <iostream>

using std::cout;
using std::cin;

int nums[20][20] = {0};
bool flags[20][20] = {false};

int main()
{
	int a, b;
	int n;

	cin >> a >> b;
	cin >> n;

	int x, y;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		flags[x][y] = true;
	}

	nums[1][1] = 1;
	for (int i = 1; i <= a; ++i)
	{
		for (int j = 1; j <= b; ++j)
		{
			if (flags[i][j] == false)
			{
				nums[i][j] += nums[i][j - 1] + nums[i - 1][j];
			}
		}
	}

	cout << nums[a][b];

	return 0;
}
