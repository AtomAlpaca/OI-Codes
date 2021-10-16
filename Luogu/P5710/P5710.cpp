// P5710 【深基3.例2】数的性质 www.luogu.com.cn/problem/P5710 
//2021.1.7
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	long long num;	//数字应该不会太大，但是一旦呢
	cin >> num;
	bool flag1,flag2;
	flag1 = (num % 2 == 0 ? true : false);	//是偶数
	flag2 = ((4 < num and num <= 12) ? true : false);	//大于 4 且不大于 12
	//说好看完下面这段代码别喷我QAQ
	if (flag1 == true and flag2 == true) cout << "1 ";
	else cout << "0 ";
	if (flag1 == true or flag2 == true) cout << "1 ";
	else cout << "0 ";
	if (int(flag1) + int(flag2) == 1) cout << "1 ";
	else cout << "0 ";
	if (flag1 == false and flag2 == false) cout << "1";
	else cout << "0";
	return 0;
}