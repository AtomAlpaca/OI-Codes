#include <iostream>

using std::cin;
using std::cout;

int x, y, z;
int a[25][25][25];

void solve(int x, int y, int z)
{
	int ans = 0;
	if (x <= 0 or y <= 0 or z <= 0)
	{
		ans = 1;
	}
	else if (x > 20 or y > 20 or z > 20)
	{
		ans = a[20][20][20];
	}
	else
	{
		ans = a[x][y][z];
	}
	cout << "w(" << x << ", " << y << ", " << z << ") = " << ans << '\n';
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	for (int i = 0; i <= 20; ++i)
	{
		for (int j = 0; j <= 20; ++j)
		{
			for (int k = 0; k <= 20; ++k)
			{
				a[i][j][k] = 1;
			}
		}
	}
	
	for (int i = 1; i <= 20; ++i)
	{
		for (int j = 1; j <= 20; ++j)
		{
			for (int k = 1; k <= 20; ++k)
			{
				a[i][j][k] = a[i - 1][j][k] 
						   + a[i - 1][j - 1][k] 
						   + a[i - 1][j][k - 1]
						   - a[i - 1][j - 1][k - 1];
			}
		}
	}
	
	while (true)
	{
		cin >> x >> y >> z;
		if (x == y and y == z and x == -1)
		{
			break;
		}
		solve(x, y, z);
	}
	
	return 0;
}
