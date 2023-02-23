#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::set;
using std::string;

const int MAX = 1e3 + 5;

set<long long> st[MAX];
string str;
int n, m, k;
const long long MOD = (1 << 31);

long long hash(std::string s)
{
	const int len = s.size();
	long long t = 0;
	for (int i = 0; i < len; ++i)
	{
		t = t * 128 + s[i] - '0' % MOD;
	}
	return t;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> k;
		for (int j = 1; j <= k; ++j)
		{
			cin >> str;
			st[i].insert(hash(str));
		}
	}

	cin >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> str;
		long long hs = hash(str);
		for (int j = 1; j <= n; ++j)
		{
			set<long long>::iterator pos = st[j].find(hs);
			if (pos != st[j].end())
			{
				cout << j << ' ';
			}
		}
		cout << '\n';
	}
}

