#include <algorithm>
#include <iostream>

using std::cout;
using std::cin;

int main()
{
	int best;
	int * n = new int;
	cin >> best >> (*n);

	int nums[*n];

	for (int i = 0; i < *n; ++i)
	{
		cin >> nums[i];
	}

	std::sort(nums, nums + *n);

	int ans = 0, right = *n - 1, left = 0;
	while (right >= left)
	{
		if (nums[right] + nums[left] <= best)
		{
			--right;
			++left ;
			++ans;
		}
		else
		{
			--right;
			++ans;	
		}
	}
	cout << ans;
	delete n;
	return 0;
}
