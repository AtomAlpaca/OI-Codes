#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int MAX = 1e5 + 5;

int n, l, r;
bool f[MAX];
int c[MAX], b[MAX];

bool cmp(int x, int y)
{
	return x < y;
}

bool judge(int x)
{
	int pos = n - x + 1;
	
	for (int i = 1; i < x; ++i)
	{
		b[i] = c[i];
	}

	std::sort(b + 1, b + x, cmp);

	for (int i = 1; i < x; ++i)
	{
		if (b[i] < pos)
		{
			++pos;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> c[i];
	}

	l = 1, r = n + 1;
	while (l != r)
	{
		int k = l + ((r - l) >> 1);
		if (judge(k))
		{
			l = k + 1;
		}
		else
		{
			r = k;
		}
	}

	cout << n - l + 1;
}

