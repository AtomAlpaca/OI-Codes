//P5716 【深基3.例9】月份天数 www.luogu.com.cn/problem/P5716
//2021.1.28

#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
	bool flag = false;
	int year,month;
	cin >> year >> month;
	if (year % 4 == 0 and year % 100 != 0)
	{
		flag = true;
	}
	else if (year % 400 == 0)
	{
		flag = true;
	}
	else 
	{
		flag = false;
	}

	if (month == 2 and flag == true)
	{
		cout << 29;
	}
	else if (month == 2 and flag == false)
	{
		cout << 28;
	}
	else if (month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12)
	{
		cout << 31;
	}
	else
	{
		cout << 30;
	}
	return 0;
}