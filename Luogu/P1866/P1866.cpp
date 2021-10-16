#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	long long ans = 1;
	int * n = new int;
	cin >> *n;
	int nums[*n];
	for (int i = 0; i < *n; ++i)
	{
		cin >> nums[i];
	}
	sort(nums,nums + *n);
	for (int i = 0; i < *n; ++i)
	{
		ans *= (nums[i] - i);
		ans %= 1000000007;
	}
	cout << ans;
	delete n;
	return 0;
}