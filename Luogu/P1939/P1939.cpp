#include <iostream>

using std::cin;
using std::cout;

const long long MOD = 1e9 + 7;
long long T, n;

struct Matrix
{
	long long a[4][4];
	Matrix()
	{
		for (int i = 1; i <= 3; ++i)
		{
			for (int j = 1; j <= 3; ++j)
			{
				a[i][j] = 0;
			}
		}
	}
};

Matrix mul(Matrix m1, Matrix m2)
{
	Matrix m3;
	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			for (int k = 1; k <= 3; ++k)
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
	cin >> T;
	while (T--)
	{
		cin >> n;
		if (n <= 3)
		{
			cout << 1 << '\n';
			continue;
		}
		Matrix p, q;
		p.a[1][1] = p.a[1][2] = p.a[1][3] = 1;
		q.a[1][1] = q.a[1][2] = q.a[2][3] = q.a[3][1] = 1;
		q = pow(q, n - 3);
		p = mul(p, q);
		cout << (p.a[1][1] + MOD) % MOD << '\n';
	}

}
