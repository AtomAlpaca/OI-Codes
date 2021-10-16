#include <bits/stdc++.h>
using namespace std;

int func(int a,int b)
{
	int ans = a;
	while (b % a != 0)
	{
		ans = b % a;
		b = a;
		a = ans;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int nums[3],n;
	for (int i = 0; i < 3; ++i)
	{
		cin >> nums[i];
	}
	sort(nums,nums + 3);
	n = func(nums[0],nums[2]);
	cout << nums[0] / n << "/" << nums[2] / n;
	return 0;
}