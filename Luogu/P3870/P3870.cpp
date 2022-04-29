#include <iostream>

using std::cin;
using std::cout;

int n, m, op, x, y;
int d[400005];
bool laz[400005];

void update(int l, int r, int s, int t, int p)
{
	if (l <= s and r >= t)
	{
		d[p] = (t - s + 1) - d[p];
		laz[p] = !laz[p];
		return ;
	}
	
	int k = s + ((t - s) >> 1);

	if (laz[p])
	{
		d[p << 1] = (k - s + 1) - d[p << 1];
		d[(p << 1) + 1] = (t - k) - d[(p << 1) + 1];
		laz[p << 1] = !laz[p << 1];
		laz[(p << 1) + 1] = !laz[(p << 1) + 1];
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

	d[p] = d[p << 1] + d[(p << 1) + 1];

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
		d[p << 1] = (k - s + 1) - d[p << 1];
		d[(p << 1) + 1] = (t - k) - d[(p << 1) + 1];
		laz[p << 1] = !laz[p << 1];
		laz[(p << 1) + 1] = !laz[(p << 1) + 1];
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

	d[p] = d[p << 1] + d[(p << 1) + 1];

	return sum;
}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	cin >> n >> m;

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
