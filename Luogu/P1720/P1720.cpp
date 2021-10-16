// P1720 月落乌啼算钱（斐波那契数列） www.luogu.com.cn/problem/P1720
// 2021.2.1
#include <bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	double ans = (pow((1 + sqrt(5)) / 2,n) - pow( ( (1 - sqrt(5) ) / 2),n)) / sqrt(5);
	printf("%.2f",ans);
	return 0;
}