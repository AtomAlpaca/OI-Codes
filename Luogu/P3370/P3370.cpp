#include <bits/stdc++.h>
using namespace std;
const int MOD = 2147483647;

auto getHash(char str[]) -> long long
{
	int ans = 0;
	for (int i = 0, len = strlen(str); i < len; ++i)
	{
		ans = ans * 128 + (int(str[i])) % MOD;
	}
	return ans;
}

int main()
{
	int ans = 1;
	char temStr[10010];
	int * n = new int;
	cin >> *n;
	long long ansNums[*n];
	for (int i = 0; i < *n; ++i)
	{
		cin >> temStr;
		ansNums[i] = getHash(temStr);
	}
	sort(ansNums, ansNums + *n);
	for (int i = 0; i < (*n - 1); ++i)
	{
		if (ansNums[i] != ansNums[i + 1])
		{
			++ans;
		}
	}
	cout << ans;
	delete n;
	return 0;
}
