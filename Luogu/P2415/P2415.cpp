#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	unsigned long long ans = 0;
	int sum;
	short i = 1;
	while (cin >> sum)
	{
		++i;
		ans += sum;
	}
	ans *= pow(2,i - 2);
	cout << ans;
	return 0;
}