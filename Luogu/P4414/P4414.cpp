// P4414 [COCI2006-2007#2] ABC www.luogu.com.cn/problem/P4414
//2021.1.29
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int nums[4];
	for (int i = 0; i < 3; ++i)
	{
		cin >> nums[i];
	}
	string str;
	cin >> str;
	sort(nums,nums + 3);
	for (int i = 0; i < 3; ++i)
	{
		if (str[i] == 'A')
		{
			cout << nums[0];
		}
		else if (str[i] == 'B')
		{
			cout << nums[1];
		}
		else
		{
			cout << nums[2];
		}
		cout << " ";
	}
	return 0;
}