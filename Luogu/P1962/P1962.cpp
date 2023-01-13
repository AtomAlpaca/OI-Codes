#include <iostream>

using std::cin;
using std::cout;

const long long MOD = 1e9 + 7;
long long n;

struct Matrix
{
	long long a[3][3];

	Matrix()
	{
		for (int i = 1; i <= 2; ++i)
		{
			for (int j = 1; j <= 2; ++j)
			{
				a[i][j] = 0;
			}
		}
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
	cin >> n;
	if (n <= 2)
	{
		cout << 1;
		return 0;
	}
	Matrix p, q;
	p.a[1][1] = p.a[1][2] = p.a[2][1] = 1;
	q.a[1][1] = q.a[1][2] = 1;
	p = pow(p, n - 2);
	q = mul(q, p);
	cout << q.a[1][1] % MOD;

}
