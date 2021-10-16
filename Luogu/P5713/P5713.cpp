// P5713 【深基3.例5】洛谷团队系统 www.luogu.com.cn/problem/P5713
//2021.1.11

#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	short nums = 0;
	cin >> nums;
	int cloud = 0,local = 0;	//云端和本机
	cloud = 11 + nums * 3;		//云端用时
	local = nums * 5;			//本机用时
	if (cloud > local)			//本机用时短
	{
		cout << "Local";
	}
	else
	{
		cout << "Luogu";
	}
	return 0;
}