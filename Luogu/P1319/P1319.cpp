#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	bool flag = 0;
	int n,s = 0,nums[20000] = {0};
	cin >> n;
	while (cin >> nums[s])
	{
		++s;
	}
	int a = 0;
	for (int i = 0; i < s; ++i)
	{
		for (int j = 0; j < nums[i]; ++j)
		{
			cout << flag;
			++a;
			if (a == n)
			{
				cout << "\n";
				a = 0; 
			}
		}
		flag = !flag;
	}
	return 0;
}