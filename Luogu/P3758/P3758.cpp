#include <iostream>

using std::cin;
using std::cout;

const long long MOD = 2017;
const long long MAX = 35;

long long t, n, m, u, v, ans;

struct Matrix
{
	int a[MAX][MAX];
	Matrix()
	{
		for (int i = 1; i <= MAX - 1; ++i)
		{
			for (int j = 1; j <= MAX - 1; ++j)
			{
				a[i][j] = 0;
			}
		}
	}

	long long sum(int x)
	{
		long long s = 0;
		for (int i = 1; i <= n; ++i)
		{
			s += a[x][i];
		}
		return s;
	}
};

Matrix mul(Matrix m1, Matrix m2)
{
	Matrix m3;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= n; ++k)
			{
				m3.a[i][j] = (m3.a[i][j] + (m1.a[i][k] * m2.a[k][j]) % MOD) % MOD;
			}
		}
	}
	return m3;
}

Matrix pow(Matrix m, long long x)
{
	Matrix t = m;
	--x;
	while (x)
	{
		if (x & 1)
		{
			t = mul(t, m);
		}
		m = mul(m, m);
		x >>= 1;
	}
	return t;
}

int main()
{
	Matrix p, q;
	cin >> n >> m;
	++n;
	while (m--)
	{
		cin >> u >> v;
		q.a[u][v] = q.a[v][u] = 1;
	}
	cin >> t;
	for (int i = 1; i <= n; ++i)
	{
		q.a[i][i] = 1;
		q.a[i][n] = 1;
	}

	q = pow(q, t);
	for (int i = 1; i <= n; ++i)
	{
		ans = (ans + q.a[1][i]) % MOD;
	}

	cout << ans;
	return 0;
}
