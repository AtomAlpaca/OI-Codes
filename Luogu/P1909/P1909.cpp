//P1909 [NOIP2016 普及组] 买铅笔 www.luogu.com.cn/problem/P1909
//2021.1.21
#include <iostream>
using namespace std;
short nums;
short s1,s2,s3;
short p1,p2,p3;
short i1,i2,i3;
long long ans1,ans2,ans3,ans;
int main(int argc, char const *argv[])
{
	cin >> nums >> s1 >> p1 >> s2 >> p2 >> s3 >> p3;
	while(i1 < nums)
	{
		ans1 += p1;
		i1 += s1;
	}
	while(i2 < nums)
	{
		ans2 += p2;
		i2 += s2;
	}
	while(i3 < nums)
	{
		ans3 += p3;
		i3 += s3;
	}
	ans = ans1;
	if (ans2 < ans)
	{
		ans = ans2;
	}
	if (ans3 < ans)
	{
		ans = ans3;
	}
	cout << ans;
	return 0;
}