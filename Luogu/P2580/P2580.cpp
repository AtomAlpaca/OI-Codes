#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 5e5 + 5;

int m, n, cnt = 1;
std::string str;
int nxt[MAX][27];
bool end[MAX], vis[MAX];

void ins(std::string s)
{
	const int len = s.length();
	int p = 1;
	for (int i = 0; i < len; ++i)
	{
		int c = s[i] - '0';
		if (!nxt[p][c])
		{
			nxt[p][c] = ++cnt;
		}
		p = nxt[p][c];
	}
	end[p] = true;
}

std::string find(std::string s)
{
	const int len = s.length();
	int p = 1;
	for (int i = 0; i < len; ++i)
	{
		int c = s[i] - '0';
		if (!nxt[p][c])
		{
			return "WRONG\n";
		}
		p = nxt[p][c];
	}
	if (end[p])
	{
		if (!vis[p])
		{
			vis[p] = true;
			return "OK\n";
		}
		else
		{
			return "REPEAT\n";
		}
	}
	else
	{
		return "WRONG\n";
	}
}	

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> str;
		ins(str);
	}
	cin >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> str;
		cout << find(str);
	}
	return 0;
}

