//P1055 [NOIP2008 普及组] ISBN 号码 www.luogu.com.cn/problem/P1055
//2021.1.28
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	string ISBN;
	cin >> ISBN;
	long long num = ((ISBN[0] -'0') * 1) + ((ISBN[2] -'0') * 2) + ((ISBN[3] -'0') * 3)
			+ ((ISBN[4] -'0') * 4) + ((ISBN[6] -'0') * 5) + ((ISBN[7] -'0') * 6)
			+ ((ISBN[8] -'0') * 7) + ((ISBN[9] -'0') * 8) + ((ISBN[10]-'0') * 9);
	num = num % 11;
	if (num < 10 and int(ISBN[12] - '0') == num)
	{
		cout << "Right";
	}
	else if (num == 10 and ISBN[12] == 'X')
	{
		cout << "Right";
	}
	else
	{
		for (int i = 0; i < 12; ++i)
		{
			cout << ISBN[i];
		}
		if (num == 10)
		{
			cout << "X";
		}
		else
		{
			cout << num;
		}
	}
	return 0;
}