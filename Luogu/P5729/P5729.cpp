#include <iostream>

using std::cin;
using std::cout;

bool nums[25][25][25] = {0};

int main()
{
	int ans = 0;
	int w, x, h;
	int q;
	int x1, x2, y1, y2, z1, z2;

	cin >> w >> x >> h;

	cin >> q;

	for (int i = 0; i < q; ++i)
	{
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		for (int a = x1; a <= x2; ++a)
		{
			for (int b = y1; b <= y2; ++b)
			{
				for (int c = z1; c <= z2; ++c)
				{
					nums[a][b][c] = 1;
				}
			}
		}
	}

	for (int a = 1; a <= w; ++a)
	{
		for (int b = 1; b <= x; ++b)
		{
			for (int c = 1; c <= h; ++c)
			{
				if (nums[a][b][c] == 0)
				{
					++ans;
				}
			}
		}
	}

	cout << ans;

	return 0;
}
