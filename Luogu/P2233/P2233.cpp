#include <iostream>

using std::cin;
using std::cout;

const long long MOD = 1e3;
long long n;

struct Matrix
{
	long long a[3][3];
	Matrix()
	{
		a[1][1] = a[1][2] = a[2][1] = a[2][2] = 0;
	}
};

Matrix mul(Matrix m1, Matrix m2)
{
	Matrix m3;
	for (int i = 1; i <= 2; ++i)
	{
		for (int j = 1; j <= 2; ++j)
		{
			for (int k = 1; k <= 2; ++k)
			{
				m3.a[i][j] = (m3.a[i][j] + (m1.a[i][k] * m2.a[k][j] % MOD)) % MOD;
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
	cin >> n;
	if (n & 1 or n == 2)
	{
		cout << 0;
		return 0;
	}
	else if (n == 4)
	{
		cout << 1;
		return 0;
	}

	n >>= 1;
	Matrix p, q;
	p.a[1][1] = 2;
	q.a[1][1] = 4, q.a[1][2] = 1, q.a[2][1] = -2;
	q = pow(q, n - 2);
	p = mul(p, q);
	cout << ((p.a[1][1] + MOD) % MOD);
	return 0;
}
