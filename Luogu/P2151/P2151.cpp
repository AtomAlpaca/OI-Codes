#include <iostream>

using std::cin;
using std::cout;

long long u, v, A, B, n, m, t;
const long long MAX = 55;
const long long MOD = 45989;

struct Matrix
{
	int a[MAX][MAX];
	Matrix()
	{
		for (int i = 1; i < MAX; ++i)
		{
			for (int j = 1; j < MAX; ++j)
			{
				a[i][j] = 0;
			}
		}
	}
};

Matrix mul(Matrix m1, Matrix m2)
{
	Matrix m3;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == j)
			{
				continue;
			}
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
	while(x)
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
	Matrix q;
	cin >> n >> m >> t >> A >> B;
	while (m--)
	{
		cin >> u >> v;
		q.a[u + 1][v + 1] = q.a[v + 1][u + 1] = 1;
	}
	q = pow(q, t);
	cout << q.a[A + 1][B + 1];
	return 0;
}
