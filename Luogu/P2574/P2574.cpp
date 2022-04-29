#include <iostream>

using std::cin;
using std::cout;

char ch;
int n, m, op, x, y;
int a[200005], d[1000005];
bool laz[1000005];

void pushup(int p)
{
	d[p] = d[p << 1] + d[(p << 1) + 1];
	return ;
}


void build(int l, int r, int p)
{
	if (l == r)
	{
		d[p] = a[l];
		return ;
	}

	int k = l + ((r - l) >> 1);

	build(l, k, p << 1);
	build(k + 1, r, (p << 1) + 1);

	pushup(p);

	return ;
}

void update(int l, int r, int s, int t, int p)
{
	if (l <= s and r >= t)
	{
		d[p] = (t - s + 1) - d[p];
		laz[p] ^= 1;
		return ;
	}

	int k = s + ((t - s) >> 1);

	if (laz[p])
	{
		laz[p << 1] ^= 1;
		laz[(p << 1) + 1] ^= 1;
		d[p << 1] = (k - s + 1) - d[p << 1];
		d[(p << 1) + 1] = (t - k) - d[(p << 1) + 1];
		laz[p] = false;
	}

	if (l <= k)
	{
		update(l, r, s, k, p << 1);
	}

	if (r > k)
	{
		update(l, r, k + 1, t, (p << 1) + 1);
	}

	pushup(p);

	return ;
}

int getsum(int l, int r, int s, int t, int p)
{
	if (l <= s and r >= t)
	{
		return d[p];
	}

	int k = s + ((t - s) >> 1);

	if (laz[p])
	{
		laz[p << 1] ^= 1;
		laz[(p << 1) + 1] ^= 1;
		d[p << 1] = (k - s + 1) - d[p << 1];
		d[(p << 1) + 1] = (t - k) - d[(p << 1) + 1];
		laz[p] = false;
	}
	
	int sum = 0;

	if (l <= k)
	{
		sum += getsum(l, r, s, k, p << 1);
	}

	if (r > k)
	{
		sum += getsum(l, r, k + 1, t, (p << 1) + 1);
	}
	
	pushup(p);
	return sum;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		cin >> ch;
		a[i] = int(ch - '0');
	}

	build(1, n, 1);

	while (m--)
	{
		cin >> op >> x >> y;
		if (op == 0)
		{
			update(x, y, 1, n, 1);
		}
		else
		{
			cout << getsum(x, y, 1, n, 1) << '\n';
		}
	}

	return 0;
}
