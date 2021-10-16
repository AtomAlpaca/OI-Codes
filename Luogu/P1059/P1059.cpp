#include <bits/stdc++.h>
using namespace std;
bool flags[1000];
int ans;
int main(int argc, char const *argv[])
{
	int * n = new int;
	cin >> *n;
	int nums[*n];
	for (int i = 0; i < 1000; ++i)
	{
		flags[i] = false;
	}
	for (int i = 0; i < *n; ++i)
	{
		cin >> nums[i];
		flags[nums[i]] = true;
	}
	for (int i = 0; i < 1000; ++i)
	{
		if (flags[i] == true)
		{
			++ans;
		}
	}
	cout << ans << endl;
	for (int i = 0; i < 1000; ++i)
	{
		if (flags[i] == true)
		{
			cout << i << " ";
		}
	}
	delete n;
	return 0;
}