#include <iostream>

using std::cin;
using std::cout;

const int MAX = 55;

int m, n, t;
int a[MAX][MAX], ans[MAX][MAX], g[MAX][2505];
int f[MAX][MAX][MAX][3];

void solve(int x)
{
	f[x][1][0][2] = 0;
	if (a[x][1] == 1)
	{
		f[x][1][1][1] = 1;
		f[x][1][1][0] = 0;
	}
	else
	{
		f[x][1][1][1] = 0;
		f[x][1][1][0] = 1;
	}

	for (int i = 2; i <= m; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			f[x][i][j][2] = std::max(f[x][i - 1][j][0], std::max(f[x][i - 1][j][1], f[x][i - 1][j][2]));
			f[x][i][j][0] = std::max(f[x][i - 1][j][0], std::max(f[x][i - 1][j - 1][1], f[x][i - 1][j - 1][2]));
			f[x][i][j][1] = std::max(f[x][i - 1][j][1], std::max(f[x][i - 1][j - 1][0], f[x][i - 1][j - 1][0]));
			if (a[x][i] == 0)
			{
				++f[x][i][j][0];
			}
			else
			{
				++f[x][i][j][1];
			}
		}
	}

	for (int i = 1; i <= m; ++i)
	{
		ans[x][i] = std::max(f[x][m][i][0], std::max(f[x][m][i][1], f[x][m][i][2]));
	//	cout << ans[x][i] << ' ';
	}

	//cout << '\n';
	return ;
}

int main()
{
	std::string str;

	cin >> n >> m >> t;
	for (int i = 1; i <= n; ++i)
	{
		cin >> str;
		for (int j = 1; j <= m; ++j)
		{
			a[i][j] = int(str[j - 1] - '0');
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		solve(i);
	}

	for (int i = 1; i <= m; ++i)
	{
		g[1][i] = ans[1][i];
	}

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= i * m; ++j)
		{
			for (int k = 0; k <= j; ++k)
			{
				g[i][j] = std::max(g[i][j], g[i - 1][k] + ans[i][j - k]);
			}
		}
	}

	int fi = 0;

	for (int i = 1; i <= n * m and i <= t; ++i)
	{
		fi = std::max(fi, g[n][i]);
	}

	cout << fi;
	return 0;
}
