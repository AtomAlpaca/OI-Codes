#include <iostream>

using std::cin;
using std::cout;

const int MAX = 105;
const int MOD = 1e9 + 7;

long long n, k;

struct Matrix
{
	long long a[MAX][MAX] = {0};
	Matrix()
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				a[i][j] = 0;
			}
		}
	}
} m;

Matrix mul(Matrix m1, Matrix m2)
{
	Matrix m3;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= n; ++k)
			{
				m3.a[i][j] += (m1.a[i][k] * m2.a[k][j]) % MOD;
				m3.a[i][j] %= MOD;
			}
		}
	}
	return m3;
}

Matrix pow(Matrix x, long long k)
{
	Matrix t = x;
	--k;
	while (k)
	{
		if (k & 1)
		{
			t = mul(x, t);
		}
		x = mul(x, x);
		k >>= 1;
	}
	return t;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> m.a[i][j];
		}
	}
	m = pow(m, k);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << m.a[i][j] << ' ';
		}
		cout << '\n';
	}
}
