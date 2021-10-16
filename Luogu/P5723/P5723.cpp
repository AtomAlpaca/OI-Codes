//P5723 【深基4.例13】质数口袋 www.luogu.com.cn/problem/P5723
//2021.1.31
#include <iostream>
using namespace std;

bool is(int num)
{
	for (int i = 2; i < num; ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int l;
	int ans = 1;
	int now = 3;
	cin >> l;
	if (l == 1)
	{
		cout << 0;
		return 0;
	}
	int add = 2;
	cout << 2 << endl;
	while(add <= l)
	{
		if (is(now) == true)
		{
			if (add + now > l)
			{
				break;
			}
			add += now;
			ans++;
			cout << now << endl;
		}
		now += 2;
	}
	cout << ans;
	return 0;
}