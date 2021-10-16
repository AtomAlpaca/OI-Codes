//P5715 【深基3.例8】三位数排序 www.luogu.com.cn/problem/P5715
//2021.1.11
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int nums[3];
	cin >> nums[0] >> nums[1] >> nums[2];
	sort(nums,nums + 3);	//有现成的sort还不用？
	cout << nums[0] << " " << nums[1] << " " << nums[2];
	return 0;
}