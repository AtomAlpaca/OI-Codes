#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 5e5 + 5;

int m, n, cnt = 1, k;
std::string str;
int nxt[MAX][2], sum[MAX];
int end[MAX];

void ins()
{
	cin >> k;
	int p = 1;
	for (int i = 1; i <= k; ++i)
	{
		int c;
		cin >> c;
		if (!nxt[p][c])
		{
			nxt[p][c] = ++cnt;
		}
		p = nxt[p][c];
		++sum[p];
	}
	++end[p];
}

int find()
{
	cin >> k;
	int p = 1, ans = 0;
	for (int i = 1; i <= k; ++i)
	{
		int c;
		cin >> c;

		if (!nxt[p][c])
		{
			for (int j = i + 1; j <= k; ++j)
			{
				cin >> c;
			}
			return ans;
		}
		p = nxt[p][c];
		ans += end[p];
	}
	return ans - end[p] + sum[p];
}

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i)
	{
		ins();
	}

	for (int i = 1; i <= m; ++i)
	{
		cout << find() << '\n';
	}
	return 0;
}

