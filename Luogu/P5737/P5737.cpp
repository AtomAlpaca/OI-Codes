#include <bits/stdc++.h>
using namespace std;

bool isYear(int num)
{
	if ((num % 4 == 0 and num % 100 != 0) or (num % 400 == 0))
	{
		return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int x,y;
	cin >> x >> y;
	int num = 0;
	int ans[1000];
	for (int i = x; i <= y; ++i)
	{
		if (isYear(i))
		{
			ans[num] = i;
			++num;
		}
	}
	cout << num << endl;
	for (int i = 0; i < num; ++i)
	{
		cout << ans[i] << " ";
	}
	return 0;
}