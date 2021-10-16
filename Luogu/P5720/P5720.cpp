//P5720 【深基4.例4】一尺之棰 www.luogu.com.cn/problem/P5720
//2021.1.29
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	long long a;
	short ans = 1;
	cin >> a;
	while (a != 1)
	{
		a = floor(a / 2);
		++ans;
	}
	cout << ans;
	return 0;
}