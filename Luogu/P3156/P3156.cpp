#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int * n = new int;
	int m;
	cin >> *n >> m;
	int nums[*n];
	for (int i = 0; i < *n; ++i)
	{
		cin >> nums[i];
	}
	int sum;
	for (int i = 0; i < m; ++i)
	{
		cin >> sum;
		cout << nums[sum - 1] << endl;
	}
	delete n;
	return 0;
}