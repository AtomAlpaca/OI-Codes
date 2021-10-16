// P1980 [NOIP2013 普及组] 计数问题 www.luogu.com.cn/problem/P1980
//2021.1.29
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,x;
	cin >> n >> x;
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		string str = to_string(i);
		for (int i = 0,len = str.length(); i < len; ++i)
		{
			if (int(str[i] - '0') == x)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}