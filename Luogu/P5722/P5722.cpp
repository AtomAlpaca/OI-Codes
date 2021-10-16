//P5722 【深基4.例11】数列求和 www.luogu.com.cn/problem/P5722
//2021.1.31
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	short n,ans;
	cin >> n;
	for (short i = 1; i <= n; ++i)
	{
		ans += i;
	}
	cout << ans;
	return 0;
}