//P5714 【深基3.例7】肥胖问题 www.luogu.com.cn/problem/P5714
//2021.1.28
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	float m,h;
	cin >> m >> h;
	float ans = m / (h * h);
	if (ans < 18.5)
	{
		cout << "Underweight";
	}
	else if (ans >= 18.5 and ans < 24)
	{
		cout << "Normal";
	}
	else
	{
		cout << ans << endl << "Overweight";
	}
	return 0;
}