#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int l,r,ans = 0;
	string str;
	cin >> l >> r;
	for (int i = l; i <= r; ++i)
	{
		str = to_string(i);
		for (int j = 0,len = str.length(); j < len; ++j)
		{
			if (str[j] == '2')
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}