// 参考 P1469
// 利用位运算
// x ^ y ^ x = y
#include <iostream>

using std::cout;
using std::cin;

int main()
{
	int ans = 0, t, n;
	double a;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> t;
		for (int j = 1; j <= t; ++j)
		{
			ans ^= int (j * a);
		}
	}
	cout << ans;
	return 0;
}
