//P1046 [NOIP2005 普及组] 陶陶摘苹果 www.luogu.com.cn/problem/P1046
//2021.1.28
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	short nums[10];
	short len;
	short ans;
	for (int i = 0; i < 10; ++i)
	{
		cin >> nums[i];
	}
	cin >> len;
	for (int i = 0; i < 10; ++i)
	{
		if (len + 30 >= nums[i])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}