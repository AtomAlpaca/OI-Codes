#include <iostream>

using std::cin;
using std::cout;

int main()
{
	int n, T, last, num, ans = 0;
	cin >> n >> T >> last;
	ans = T;
	for (int i = 1; i < n; ++i)
	{
		cin >> num;
		if (last + T > num)
		{
			ans += T;
			ans -= last + T - num;
		}
		else
		{
			ans += T;
		}
		last = num;
	}
	cout << ans;
	return 0;
}
