#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int * n = new int;
	cin >> *n;

	short nums[*n];
	int add = 0;
	int ans = 0;
	bool flag[*n];
	for (int i = 0; i < *n; ++i)
	{
		cin >> nums[i];
		flag[i] = false;
	}
	for (int i = 0; i < *n; ++i)
	{
		for (int j = i + 1;j < *n;++j)
		{
			add = nums[i] + nums[j];
			for (int k = 0; k < *n; ++k)
			{
				if (add == nums[k] and flag[k] != true)
				{
					++ans;
					flag[k] = true;
				}
			}
		}
	}
	cout << ans;
	delete n;
	return 0;
}