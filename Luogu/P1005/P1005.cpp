#include <bits/stdc++.h>

using std::cin;
using std::cout;

int m, n;

int a[85][85];

__int128 ans;
__int128 power[80];
__int128 f[85][85];

void init(int x)
{
	__int128 p = 1;
	for (int i = 0; i <= x; ++i)
	{
		power[i] = p;
		p <<= 1;
	}
	return ;
}

void clear()
{
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			f[i][j] = 0;
		}
	}
}
void Print(__int128 x)
{
    if(x == 0) 
	{
		return ;
	}
    Print(x / 10);
    putchar(x % 10 + '0');
}

int main()
{
	cin >> n >> m;

	init(m);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		clear();
		for (int j = m - 1; j >= 1; --j)
		{
			for (int k = 1; k + j - 1 <= m; ++k)
			{
				f[k][k + j - 1] = std::max(f[k][k + j - 1], 
										   f[k][k + j] + a[i][k + j] * power[m - j]);
				f[k][k + j - 1] = std::max(f[k][k + j - 1],
										   f[k - 1][k + j - 1] + a[i][k - 1] * power[m - j]);
			}
		}

		__int128 o = -1;

		for (int j = 1; j <= m; ++j)
		{
			o = std::max(o, f[j][j] + a[i][j] * power[m]);
		}
		ans += o;
	}

	if (ans == 0)
	{
		cout << 0;
	}
	else
	{
		Print(ans);
	}
	return 0;
}
