// P5717 【深基3.习8】三角形分类 www.luogu.com.cn/problem/P5717
//2021.1.28
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int nums[4];
	for (int i = 0; i < 3; ++i)
	{
		cin >> nums[i];
	}
	sort(nums,nums + 3);
	if(nums[0] + nums[1] <= nums[2])
	{
		cout << "Not triangle\n";
		return 0;
	}
	if (nums[0] * nums[0] + nums[1] * nums[1] < nums[2] * nums[2])
	{
		cout << "Obtuse triangle\n";
	}
	else if (nums[0] * nums[0] + nums[1] * nums[1] > nums[2] * nums[2])
	{
		cout << "Acute triangle\n";
	}
	else if (nums[0] * nums[0] + nums[1] * nums[1] == nums[2] * nums[2])
	{
		cout << "Right triangle\n";
	}

	if (nums[0] == nums[1] or nums[1] == nums[2] or nums[0] == nums[2])
	{
		cout << "Isosceles triangle\n";
	}
	if (nums[0] == nums[1] and nums[1] == nums[2])
	{
		cout << "Equilateral triangle\n";
	}
	return 0;
}