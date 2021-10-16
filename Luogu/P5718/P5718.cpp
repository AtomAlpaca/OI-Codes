//P5718 【深基4.例2】找最小值 www.luogu.com.cn/problem/P5718
//2021.1.29
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int * n = new int;
	cin >> *n;
	int a[*n];
	for (int i = 0; i < *n; ++i)
	{
		cin >> a[i];
	}
	sort(a,a + *n);
	cout << a[0];
	delete n;
	return 0;
}