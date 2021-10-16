//P1422 小玉家的电费 www.luogu.com.cn/problem/P1422
//2021.1.15
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	double ans;
	int power;
	cin >> power;
	if (power <= 150)
	{
		ans = double(power) * 1.0 * 0.4463;
	}
	else if(power > 150 and power <= 400)
	{
		ans = (150 * 1.0 * 0.4463) + ((power - 150) * 1.0 * 0.4663);
	}
	else
	{
		ans = 150 * 1.0 * 0.4463 + 250 * 0.4663 + (power - 400) * 0.5663;
	}
	cout << floor((ans * 10.0) + 0.5) / 10.0;
	return 0;
}