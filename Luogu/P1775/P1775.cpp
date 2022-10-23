#include <iostream>

using std::cin;
using std::cout;

const int MAX = 305;
const int INF = 0x3f3f3f3f;
int n;
int a[MAX], sum[MAX];
int f[MAX][MAX];

int main()
{

	cin >> n;
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			f[i][j] = INF;
		}
	}
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
		f[i][i] = 0;
	}
	
	for (int k = 1; k < n; ++k)
	{
		for (int i = 1; i + k <= n; ++i)
		{
			for (int j = 1; j < i + k; ++j)
			{
				f[i][i + k] = std::min(f[i][i + k], f[i][j] + f[j + 1][i + k] + sum[i + k] - sum[i - 1]);
			}
		}
	}
	
	cout << f[1][n];
	return 0;
}

