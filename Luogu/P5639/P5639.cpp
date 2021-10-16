#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int ans = 1;
	int * n = new int;
	int sum,num = 0;
	cin >> *n;
	for (int i = 0; i < *n; ++i)
	{
		cin >> sum;
		if (sum != num)
		{
			num = sum;
			++ans;
		}
	}
	cout << ans;
	delete n;
	return 0;
}