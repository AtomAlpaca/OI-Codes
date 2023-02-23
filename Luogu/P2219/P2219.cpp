#include <iostream>

using std::cin;
using std::cout;

const int MAX = 1e3 + 5;

int ans;
long long m, n, A, B, C, D;
long long q[MAX], h, t;
long long a[MAX][MAX], s[MAX][MAX], o[MAX][MAX], p[MAX][MAX], u[MAX][MAX], v[MAX][MAX];

long long cal(long long x, long long y, long long l, long long r)
{
	return s[x + l - 1][y + r - 1] - s[x - 1][y + r - 1] - s[x + l - 1][y - 1] + s[x - 1][y - 1];
}

int main()
{
	cin >> m >> n >> A >> B >> C >> D;

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> a[i][j];
			s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
		}
	}

	for (int i = 1; i + A - 1 <= m; ++i)
	{
		for (int j = 1; j + B - 1 <= n; ++j)
		{
			o[i][j] = cal(i, j, A, B);
		}
	}

	for (int i = 2; i + C - 1 <= m; ++i)
	{
		for (int j = 2; j + D - 1 <= n; ++j)
		{
			p[i][j] = cal(i, j, C, D);
		}
	}

	for (int i = 1; i <= m; ++i)
	{
		h = 1;
		t = 0;
		int k = B - D - 1;
		for (int j = 1; j <= k; ++j)
		{
			while (t >= h and p[i][q[t]] > p[i][j])
			{
				--t;
			}
			++t;
			q[t] = i;
		}
		for (int j = 2; j + k + C - 1 <= n; ++j)
		{
			while (t >= h and j > q[h])
			{
				++h;
			}
			while (t >= h and p[i][q[t]] >= p[i][j + k])
			{
				--t;
			}
			++t;
			q[t] = j + k;
			u[i][j] = p[i][q[h] - k];
		}
	}

	for (int i = 1; i + B - 2 <= n; ++i)
	{
		h = 1; t = 0;
		int k = A - C - 1;
		for (int j = 1; j <= k; ++j)
		{
			while (t >= h and u[q[t]][i] > u[j][i])
			{
				--t;
			}
			++t;
			q[t] = i;
		}
		for (int j = 1; j + k + D - 1 <= m; ++j)
		{
			while (t >= h and q[h] < j)
			{
				++h;
			}
			while (t >= h and u[q[t]][i] >= u[j + k][i])
			{
				--t;
			}
			++t;
			q[t] = j + k;
			v[j][i] = u[q[h] - k][i];
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << u[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i + A - 1 <= m; ++i)
	{
		for (int j = 1; j + B - 1<= n; ++j)
		{
			ans = std::max(ans, (int)(o[i][j] - v[i + 1][j + 1]));
		}
	}

	cout << ans;
	return 0;
}
