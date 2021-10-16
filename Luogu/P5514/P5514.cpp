#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int * n = new int;
	int ans = 0;
	int sum;
	cin >> *n;
	for (int i = 0; i < *n; ++i)
	{
		cin >> sum;
		ans ^= sum;
	}
	cout << ans;
	delete n;
	return 0;
}