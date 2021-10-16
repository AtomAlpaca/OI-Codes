#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	int ans = 0;
	cin >> s;
	for (int i = 0; i < 8; ++i)
	{
		if (s[i] == '1')
		{
			++ans;
		}
	}
	cout << ans;
	return 0;
}