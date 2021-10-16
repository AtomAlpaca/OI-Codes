//P5719 【深基4.例3】分类平均 www.luogu.com.cn/problem/P5719
//2021.1.29
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	short n;
	short k;
	cin >> n >> k;
	long long A = 0,B = 0;
	short ANum = 0,BNum = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (i % k == 0)//能整除
		{
			A += i;
			ANum++;
		}
		else 
		{
			B += i;
			BNum++;
		}
	}
	double Aans = A * 1.0 / ANum;
	double Bans = B * 1.0/ BNum;
	cout << fixed << setprecision(1) << Aans  << " " << Bans;
	return 0;
}