//P1424 小鱼的航程(改进版) www.luogu.com.cn/problem/P1424
//2021.1.28
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int x,n;
	cin >> x >> n;
	unsigned long long ans = 0;
	for (int i = 0,j = x; i < n; ++i)
	{
		if (j != 6 and j != 7)
		{
			ans += 250;
		}
		if (j >= 7)
		{
			j = 1;
		}
		else 
		{
			j++;
		}
	}
	cout << ans;
	return 0;
}