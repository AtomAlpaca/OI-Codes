#include <iostream>

using std::cin;
using std::cout;

int last;
int INF = - (2 << 20);
int m, D, x, cnt;
char op;
int d[800005];

void build(int l, int r, int c, int s, int t, int p)
{
	if (s == t)
	{
		d[p] = c;
		return ;
	}

	int k = s + ((t - s) >> 1);

	if (k >= l)
	{
		build(l, r, c, s, k, (p << 1));
	}
	if (k < r)
	{
		build(l, r, c, k + 1, t, ((p << 1) + 1));
	}

	d[p] = std::max(d[(p << 1)], d[(p << 1) + 1]);

	return ;
}

int find(int l, int r, int s, int t, int p)
{
	if (l <= s and r >= t)
	{
		return d[p];
	}

	int k = s + ((t - s) >> 1);
	int a = INF;
	int b = INF;
	if (k >= l)
	{
		a = find(l, r, s, k, (p << 1));
	}
	if (k < r)
	{
		b = find(l, r, k + 1, t, (p << 1) + 1);
	}

	return std::max(a, b);
}

int main()
{
	cin >> m >> D;
	int T = m;
	
	for (int i = 0; i <= T; ++i)
	{
		d[i] = INF;
	}

	while (T--)
	{
		cin >> op >> x;
		if (op == 'Q')
		{
			if (cnt == 0)
			{
				cout << 0 << '\n';
			}
			else
			{
				last = find(cnt - x + 1, cnt, 1, m, 1);
				cout << last << '\n';
			}
		}
		else
		{
			build(cnt + 1, cnt + 1, (x + last) % D, 1, m, 1);
			++cnt;
		}
	}
	return 0;
}
