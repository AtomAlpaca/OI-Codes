#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	long long n,a[1001];
	short ans = 0,num = 1;
	cin >> n;
	for (long long i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (i > 0 and (a[i] == a[i - 1] + 1 or a[i] == a[i - 1] - 1))
		{
			num++;
		}
		else
		{
			if (ans < num)
			{
				ans = num;
			}
			num = 1;
		}
	}
	cout << ans;
	return 0;
}