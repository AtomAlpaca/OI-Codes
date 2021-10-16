#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n1,n2;
	int ans[10] = {0};
	cin >> n1 >> n2;
	for (int i = n1; i <= n2; ++i)
	{
		string s = to_string(i);
		for (int j = 0,len = s.length(); j < len; ++j)
		{
			++ans[int(s[j] - '0')];
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << ans[i] << " ";
	}
	return 0;
}