//P5721 【深基4.例6】数字直角三角形 www.luogu.com.cn/problem/P5721
//2021.1.29
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	short n;
	cin >> n;
	int num = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i; j <= n; ++j)
		{
			if (num < 10)
			{
				cout << "0" << num;
			}
			else
			{
				cout << num;
			}
			++num;
		}
		cout << endl;
	}
	return 0;
}