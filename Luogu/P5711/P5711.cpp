//P5711 【深基3.例3】闰年判断 www.luogu.com.cn/problem/P5711
//2021.1.28

#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	long long year;
	cin >> year;
	if (year % 4 == 0 and year % 100 != 0)
	{
		cout << 1;
	}
	else if (year % 400 == 0)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}