#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;

int main()
{
	int lens[40] = 
	{
		0,
		990,
		1010,
		1970,
		2030,
		2940,
		3060,
		3930,
		4060,
		4970,
		5030,
		5990,
		6010,
		7000
	};

	int ans[40];

	short now = 14;
	int min, max, n;
	
	cin >> min >> max;

	cin >> n;
	for (int i = 0; i < n; ++i, ++now)
	{
		cin >> lens[now];
	}

	std::sort(lens, lens + now);

	ans[0] = 1;

	for (int i = 1; i < now; ++i)
	{
		ans[i] = 0;
		for (int j = i - 1; j >= 0; --j)
		{
			if (lens[i] - lens[j] >= min and lens[i] - lens[j] <= max)
			{
				ans[i] += ans[j];
			}
		}
	}

	cout << ans[now - 1];

	return 0;
}
