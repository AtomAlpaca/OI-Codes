#include <iostream>

using std::cin;
using std::cout;

int n, m, MOD, op, x, y, z;
long long a[100005], d[450005], add[450005], mul[450005];

void pushdown(int s, int t, int p)
{	
	int k = p << 1;
	int q = s + ((t - s) >> 1);
	if (mul[p] != 1)
	{
		mul[k] *= mul[p];
		mul[k] %= MOD;
		mul[k + 1] *= mul[p];
		mul[k + 1] %= MOD;
		add[k] *= mul[p];
		add[k] %= MOD;
		add[k + 1] *= mul[p];
		add[k + 1] %= MOD;
		d[k] *= mul[p];
		d[k] %= MOD;
		d[k + 1] *= mul[p];
		d[k + 1] %= MOD;
		mul[p] = 1;
	}
	if (add[p])
	{
		add[k] += add[p];
		add[k] %= MOD;
		add[k + 1] += add[p];
		add[k + 1] %= MOD;
		d[k] += add[p] * (q - s + 1);
		d[k] %= MOD;
		d[k + 1] += add[p] * (t - q);
		d[k + 1] %= MOD;
		add[p] = 0;
	}
	return ;
}

void build(int l, int r, int p)
{
	mul[p] = 1;

	if (l == r)
	{
		d[p] = a[l];
		return ;
	}

	int k = l + ((r - l) >> 1);

	build(l, k, p << 1);
	build(k + 1, r, (p << 1) + 1);

	d[p] = (d[p << 1] + d[(p << 1) + 1]) % MOD;

	return ;
}

void update(int l, int r, int c, int s, int t, int p)
{
	if (l <= s and r >= t)
	{
		d[p] += c * (t - s + 1);
		add[p] += c;
		d[p] %= MOD;
		add[p] %= MOD;
		return ;
	}

	int k = s + ((t - s) >> 1);
	
	pushdown(s, t, p);

	if (l <= k)
	{
		update(l, r, c, s, k, p << 1);
	}

	if (r > k)
	{
		update(l, r, c, k + 1, t, (p << 1) + 1);
	}

	d[p] = (d[p << 1] + d[(p << 1) + 1]) % MOD;

	return ;

}

void update2(int l, int r, int c, int s, int t, int p)
{
	if (l <= s and r >= t)
	{
		d[p] *= c;
		d[p] %= MOD;
		mul[p] *= c;
		mul[p] %= MOD;
		add[p] *= c;
		add[p] %= MOD;
		return ;
	}

	int k = s + ((t - s) >> 1);
	
	pushdown(s, t, p);

	if (l <= k)
	{
		update2(l, r, c, s, k, p << 1);
	}

	if (r > k)
	{
		update2(l, r, c, k + 1, t, (p << 1) + 1);
	}

	d[p] = (d[p << 1] + d[(p << 1) + 1]) % MOD;

	return ;
}

int getsum(int l, int r, int s, int t, int p)
{
	if (l <= s and r >= t)
	{
		return d[p];
	}

	int k = s + ((t - s) >> 1);

	pushdown(s, t, p);

	long long sum = 0;

	if (l <= k)
	{
		sum += getsum(l, r, s, k, p << 1);
		sum %= MOD;
	}
	if (r > k)
	{
		sum += getsum(l, r, k + 1, t, (p << 1) + 1);
		sum %= MOD;
	}

	sum %= MOD;
	return sum;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> MOD;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	build(1, n, 1);

	cin >> m;
	
	while (m--)
	{
		cin >> op >> x >> y;
		if (op == 1)
		{
			cin >> z;
			update2(x, y, z, 1, n, 1);
		}
		else if (op == 2)
		{
			cin >> z;
			update(x, y, z, 1, n, 1);
		}
		else
		{
			cout << getsum(x, y, 1, n, 1) % MOD << '\n';
		}
	}
	return 0;
}

