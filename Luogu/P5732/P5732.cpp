#include <iostream>

using std::cout;
using std::cin;

int main()
{
	int * n = new int;
	cin >> *n;
	int nums[*n + 1][*n + 1] = {0};
	
	for (int i = 1; i <= *n; ++i)
	{
		nums[i][1] = 1;
		nums[i][i] = 1;	
	}

	for (int i = 1; i <= *n; ++i)
	{
		for (int j = 2; j < i; ++j)
		{
			nums[i][j] = nums[i - 1][j] + nums[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= *n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << nums[i][j] << " ";
		}
		cout << "\n";
	}

	delete n;
	return 0;
}
