#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::complex;

const int MAX = 3e6 + 5;
const double PI = acos(-1.0);

int rev[MAX];
complex<double> x1[MAX], x2[MAX];

void change(complex<double> f[], int len)
{
	for (int i = 0; i <= len; ++i)
	{
		rev[i] = 0;
	}
	for (int i = 0; i < len; ++i)
	{
		rev[i] = rev[i >> 1] >> 1;
		if (i & 1)
		{
			rev[i] += len >> 1;
		}
	}

	for (int i = 0; i < len; ++i)
	{
		if (i < rev[i])
		{
			std::swap(f[i], f[rev[i]]);
		}
	}
}

void FFT(complex<double> f[], int len, int on)
{
	change(f, len);

	for (int l = 2; l <= len; l <<= 1)
	{
		complex<double> step = {cos(2 * PI / l), sin(on * 2 * PI / l)};
		for (int i = 0; i < len; i += l)
		{
			complex <double> now = {1, 0};
			for (int k = i; k < i + (l >> 1); ++k)
			{
				complex <double> u = f[k];
				complex <double> v = now * f[k + (l >> 1)];

				f[k] = u + v;
				f[k + (l >> 1)] = u - v;
				now *= step;
			}
		}
	}

	if (on == -1)
	{
		for (int i = 0; i < len; ++i)
		{
			f[i].real(f[i].real() / len);
		}
	}
	return ;
}

int m, n, tmp;

int main()
{
	cin >> m >> n;
	++m, ++n;
	for (int i = 0; i < m; ++i)
	{
		cin >> tmp;
		x1[i] = {double(tmp), 0};
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		x2[i] = {double(tmp), 0};
	}
	int len = 1;
	while (len < m * 2 or len < n * 2)
	{
		len <<= 1;
	}

	for (int i = m; i < len; ++i)
	{
		x1[i] = {0, 0};
	}

	for (int i = n; i < len; ++i)
	{
		x2[i] = {0, 0};
	}

	FFT(x1, len, 1);
	FFT(x2, len, 1);

	for (int i = 0; i < len; ++i)
	{
		x1[i] *= x2[i];
	}

	FFT(x1, len, -1);

	len = m + n;

	for (int i = 0; i <= len - 2; ++i)
	{
		cout << int(x1[i].real() + 0.5) << ' ';
	}

	return 0;
}
