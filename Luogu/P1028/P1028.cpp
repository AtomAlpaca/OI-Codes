#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int * n = new int;
	cin >> *n;
	int nums[*n];
	nums[0] = 1;
	for (int i = 1; i < *n; ++i)
	{
		if ((i + 1) % 2 == 1)
		{
			nums[i] = nums[i - 1];
		}
		else
		{
			nums[i] = nums[i - 1] + nums[i / 2];
		}
	}
	cout << nums[*n - 1];
	delete n;
	return 0;
}