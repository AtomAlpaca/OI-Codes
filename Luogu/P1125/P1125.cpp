#include <bits/stdc++.h>
using namespace std;

bool isPr(int num)
{
	//几个可能出现的特殊判定
	if (num == 0 or num == 1 or num == 4)
	{
		return false;
	}
	else if (num == 2 or num == 3)
	{
		return true;
	}
	else//如果不按套路出牌
	{
		for (int i = 2; i * i < num; ++i)
		{
			if (num % i == 0)
			{
				return false;
			}
		}
		return true;
	}
}

int main(int argc, char const *argv[])
{
	string str;
	int times[26] = {0},maxn = 0,minn = 110,ans = 0;
	cin >> str;
	for (int i = 0,len = str.length(); i < len; ++i)
	{
		++times[int(str[i] - 'a')];
	}
	for (int i = 0; i < 26; ++i)
	{
		if (maxn <= times[i])
		{
			maxn = times[i];
		}
		if (minn >= times[i] and times[i] != 0)
		{
			minn = times[i];
		}
	}
	ans = maxn - minn;
	if (isPr(ans) == true)
	{
		cout << "Lucky Word" << endl;
		cout << ans;
	}
	else
	{
		cout << "No Answer"  << endl;
		cout << 0;
	}
	return 0;
}