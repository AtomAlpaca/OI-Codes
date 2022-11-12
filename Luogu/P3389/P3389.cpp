#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 105;

int n;
double a[MAX][MAX];

void swapline(int x, int y)
{
	for (int i = 1; i <= n + 1; ++i)
	{
		std::swap(a[x][i], a[y][i]);
	}
	return ;
}

void addline(int x, int y, double d)
{
	
	return ;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n + 1; ++j)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		int j = 1,  m = i;
		for (j = i + 1; j <= n; ++j)
		{
			if (std::fabs(a[j][i]) > std::fabs(a[m][i]))
			{
				m = j;
			}
		}

		if (!a[m][i])
		{
			cout << "No Solution";
			return 0;
		}

		if (m != i)
		{
			swapline(i, m);
		}

		for (int k = 1; k <= n; ++k)
		{
			if (k == i)
			{
				continue;
			}
			//cout << a[k][i] << ' ' << a[i][i] << ' ' << i << ' ';
			double div = a[k][i] / a[i][i];
			//cout << div << '\n';
			for (int l = 1; l <= n + 1; ++l)
			{
				a[k][l] -= div * a[i][l];
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		cout << std::fixed << std::setprecision(2) << a[i][n + 1] / a[i][i] << '\n';	
	}
	return 0;
}
