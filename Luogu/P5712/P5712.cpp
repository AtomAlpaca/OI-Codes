//P5712 【深基3.例4】Apples www.luogu.com.cn/problem/P5712
//2021.1.11
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	short num = 0;
	cin >> num;
	if (num > 1)
	{
		cout << "Today, I ate " << num << " apples.";	//有复数
	}
	else
	{
		cout << "Today, I ate " << num << " apple.";	//没有复数
	}
	return 0;
}