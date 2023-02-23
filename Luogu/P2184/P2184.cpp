#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 4e5 + 5;
int n, m, q, u, v, cnt;

struct ST
{
	int st[MAX];

	void pu(int x)
	{
		st[x] = st[x << 1] + st[x << 1 | 1];
	}

	void add(int l, int r, int c, int x)
	{
		if (l == r and l == c)
		{
			++st[x];
			return ;
		}
		int k = l + ((r - l) >> 1);
		if (c <= k)
		{
			add(l, k, c, x << 1);
		}
		if (c > k)
		{
			add(k + 1, r, c, x << 1 | 1);
		}
		pu(x);
		return ;
	}

	int get(int l, int r, int s, int t, int x)
	{
		if (l >= s and r <= t)
		{
			return st[x];
		}

		int k = l + ((r - l) >> 1);
		int sum = 0;
		if (s <= k)
		{
			sum += get(l, k, s, t, x << 1);
		}
		if (t > k)
		{
			sum += get(k + 1, r, s, t, x << 1 | 1);
		}
		pu(x);
		return sum;
	}
} s1, s2;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	cin >> n >> m;
	while (m--)
	{
		cin >> q >> u >> v;
		if (q == 1)
		{
			++cnt;
			s1.add(1, n, u, 1);
			s2.add(1, n, v, 1);
		}
		if (q == 2)
		{
			cout << cnt - s1.get(1, n, v + 1, n, 1) - s2.get(1, n, 1, u - 1, 1) << '\n';
		}
	}
}

