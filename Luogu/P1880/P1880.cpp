#include <iostream>

using std::cin;
using std::cout;

const int MAX = 101 << 1 | 1;
const int INF = 0x3f3f3f3f;

int n;
int a[MAX], sum[MAX];
int f[MAX][MAX], g[MAX][MAX];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		a[i + n] = a[i];
	}
	
	for (int i = 1; i <= 2 * n; ++i)
	{
		sum[i] = sum[i - 1]  + a[i];
	}
	
	for (int i = 1; i < MAX; ++i)
	{
		for (int j = 1; j < MAX; ++j)
		{
			f[i][j] = -INF;
			g[i][j] =  INF;
		}
		f[i][i] = g[i][i] = 0;
	}
	
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i + k - 1 <= 2 * n; ++i)
		{
			for (int j = i; j < i + k; ++j)
			{
				f[i][i + k] = std::max(f[i][j] + f[j + 1][i + k] + sum[i + k] - sum[i - 1], f[i][i + k]);
				g[i][i + k] = std::min(g[i][j] + g[j + 1][i + k] + sum[i + k] - sum[i - 1], g[i][i + k]);
			}
		}
	}
	
	int ans1 = INF, ans2 = -INF;
	
	for (int i = 1; i <= n; ++i)
	{
		ans1 = std::min(ans1, g[i][i + n - 1]);
		ans2 = std::max(ans2, f[i][i + n - 1]);
	}
	
	cout << ans1 << '\n' << ans2;
	return 0;
}

