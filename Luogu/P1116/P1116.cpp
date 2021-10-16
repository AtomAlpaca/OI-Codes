#include <iostream>
using std::cout;
using std::cin;

int main()
{
	int * n = new int;
	cin >> *n;
	int nums[*n], ans = 0;
	for (int i = 0; i < *n; ++i)
	{
		cin >> nums[i];
		for (int j = i; j >= 0; --j)
		{
			if (nums[j] > nums[i])
			{
				++ans;
			}
		}
	}
	cout << ans;
	delete n;
	return 0;
}
