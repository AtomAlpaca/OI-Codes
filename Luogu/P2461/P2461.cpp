#include <iostream>

using std::cin;
using std::cout;

const int MAX = 17;

long long k, m, n, MOD;
long long a[MAX], c[MAX], s[MAX];

struct Matrix
{
	long long a[17][17];
	Matrix()
	{
		for (int i = 1; i <= 15; ++i)
		{
			for (int j = 1; j <= 15; ++j)
			{
				a[i][j] = 0;
			}
		}
	}
};

Matrix mul(Matrix m1, Matrix m2)
{
	Matrix m3;
	for (int i = 1; i <= k + 1; ++i)
	{
		for (int j = 1; j <= k + 1; ++j)
		{
			for (int l = 1; l <= k + 1; ++l)
			{
				m3.a[i][j] = ((m1.a[i][l] * m2.a[l][j]) % MOD + m3.a[i][j]) % MOD;
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
	cin >> k;
	for (int i = 1; i <= k; ++i)
	{
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}

	for (int i = 1; i <= k; ++i)
	{
		cin >> c[i];
	}

	cin >> m >> n >> MOD;

	Matrix A, H;
	A.a[1][1] = 1;
	for (int i = 2; i <= k + 1; ++i)
	{
		A.a[i][1] = A.a[i][2] = (c[i - 1] % MOD);
	}

	for (int i = 3; i <= k + 1; ++i)
	{
		A.a[i - 1][i] = 1;
	}

	H.a[1][1] = s[k];
	for (int i = 2; i <= k + 1; ++i)
	{
		H.a[1][i] = a[k + 1 - i + 1] % MOD;
	}

	int d = 0, e = 0;

	if (n <= k)
	{
		d = s[n];
	}
	else
	{
		Matrix B = pow(A, n - k);
		B = mul(H, B);
		d = B.a[1][1];
	}
	if (m <= k)
	{
		e = s[m - 1];
	}
	else
	{
		Matrix C = pow(A, m - k - 1);
		C = mul(H, C);
		e = C.a[1][1];
	}
	cout << (d - e + MOD) % MOD;
	return 0;
}

