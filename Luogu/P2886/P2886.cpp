#include <iostream>

using std::cin;
using std::cout;

const long long MAX = 205;
const long long INF = 0x3f3f3f3f;

long long u, v, w, n, t, s, e, cnt;
long long mp[1005];

struct Matrix
{
	long long a[MAX][MAX];
	Matrix()
	{
		for (int i = 1; i < MAX - 1; ++i)
		{
			for (int j = 1; j < MAX - 1; ++j)
			{
				a[i][j] = INF;
			}
		}
	}
};

Matrix add(Matrix m1, Matrix m2)
{
	Matrix m3;
	for (int i = 1; i <= cnt; ++i)
	{
		for (int j = 1; j <= cnt; ++j)
		{
			for (int k = 1; k <= cnt; ++k)
			{
				m3.a[i][j] = std::min(m3.a[i][j], m1.a[i][k] + m2.a[k][j]);
			}
		}
	}
	return m3;
}

Matrix sum(Matrix m, long long x)
{
	Matrix t = m;
	--x;
	while (x)
	{
		if (x & 1)
		{
			t = add(t, m);
		}
		m = add(m, m);
		x >>= 1;
	}
	return t;
}

int main()
{
	Matrix q;
	cin >> n >> t >> s >> e;
	while (t--)
	{
		cin >> w >> u >> v;
		if (!mp[u])
		{
			++cnt;
			mp[u] = cnt;
		}
		if (!mp[v])
		{
			++cnt;
			mp[v] = cnt;
		}
		q.a[mp[u]][mp[v]] = q.a[mp[v]][mp[u]] = w;
	}
	q = sum(q, n);

	cout << q.a[mp[s]][mp[e]];
	return 0;
}
