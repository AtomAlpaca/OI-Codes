#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	long long ans = 0;
	int k,num = 1,time = 0;
	cin >> k;
	for (int i = 1; i <= k; ++i)
	{
		ans += num;
		++time;
		if (time >= num)
		{
			++num;
			time = 0;
		}
	}
	cout << ans;
	return 0;
}