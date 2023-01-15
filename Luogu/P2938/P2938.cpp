#include <iostream>

using std::cin;
using std::cout;

const int MAX = 55;

int s, d, m;
int c[MAX], v[MAX], f[500005];
int a[15][MAX];

void solve(int x)
{
	int tmp = -1;
	for (int i = 1; i <= s; ++i)
	{
		c[i] = a[x][i];
		v[i] = a[x + 1][i] - a[x][i];
	}

	for (int i = 1; i <= m; ++i)
	{
		f[i] = 0;
	}

	for (int i = 1; i <= s; ++i)
	{
		for (int j = c[i]; j <= m; ++j)
		{
			f[j] = std::max(f[j], f[j - c[i]] + v[i]);
			tmp = std::max(f[j], tmp);
		}
	}

	m += tmp;
	return ;
}

int main()
{
	cin >> s >> d >> m;
	for (int i = 1; i <= s; ++i)
	{
		for (int j = 1; j <= d; ++j)
		{
			cin >> a[j][i];
		}
	}

	for (int i = 1; i < d; ++i)
	{
		solve(i);
	}

	cout << m;
}
