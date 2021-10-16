#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int * n = new int;
	cin >> *n;
	int nums[*n];
	int ans = 0;
	for (int i = 0; i < *n; ++i)
	{
		cin >> nums[i];
		for (int j = i; j >= 0; --j)
		{
			if (nums[j] < nums[i])
			{
				++ans;
			}
		}
		cout << ans << " ";
		ans = 0;
	}
	delete n;
	return 0;
}