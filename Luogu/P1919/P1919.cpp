#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::complex;

const int MAX = 1e6 + 5;

const double PI = acos(-1.0);
int rev[MAX * 3];
int ans[MAX * 3];
complex<double> x1[MAX * 3], x2[MAX * 3];

void change(complex<double> y[], int len)
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
			rev[i] += (len >> 1);
		}
	}

	for (int i = 0; i < len; ++i)
	{
		if (i < rev[i])
		{
			std::swap(y[i], y[rev[i]]);
		}
	}
}

void FFT(complex<double> y[], int len, int on)
{
	change(y, len);

	for (int h = 2; h <= len; h <<= 1)
	{
		complex<double> step(cos(2 * PI / h), sin(on * 2 * PI / h));
		for (int i = 0; i < len; i += h)
		{
			complex<double> now = {1, 0};
			for (int k = i; k < (i + (h >> 1)); ++k)
			{
				complex<double> u = y[k];
				complex<double> v = now * y[k + (h >> 1)];
				y[k] = u + v;
				y[k + (h >> 1)] = u - v;
				now = now * step;
			}
		}
	}

	if (on == -1)
	{
		for (int i = 0; i < len; ++i)
		{
			y[i].real(y[i].real() / len);
		}
	}
}

int main()
{
	std::string a, b;
	cin >> a >> b;
	const int l1 = a.size(), l2 = b.size();
	int len = 1;
	while (len < l1 * 2 or len < l2 * 2)
	{
		len <<= 1;
	}

	for (int i = 0; i < l1; ++i)
	{
		x1[i] = {double(a[l1 - i - 1] - '0'), 0};
	}

	for (int i = 0; i < l2; ++i)
	{
		x2[i] = {double(b[l2 - i - 1] - '0'), 0};
	}

	for (int i = l1; i < len; ++i)
	{
		x1[i] = {0, 0};
	}

	for (int i = l2; i < len; ++i)
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

	for (int i = 0; i < len; ++i)
	{
		ans[i] = int(x1[i].real() + 0.5);
	}

	for (int i = 0; i < len; ++i)
	{
		ans[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}

	len = l1 + l2 - 1;
	while (len and !ans[len])
	{
		--len;
	}

	for (int i = len; i >= 0; --i)
	{
		cout << ans[i];
	}
}
