#include <iostream>

using std::cin;
using std::cout;

const int mapo[7][7] = 
{
	{0, 0, 0, 0, 0, 0},
	{0, 5, -1, -2, -1, -3},
	{0, -1, 5, -3, -2, -4},
	{0, -2, -3, 5, -2, -2},
	{0, -1, -2, -2, 5, -1},
	{0, -3, -4, -2, -1, 0}
};
const int MAX = 105;
const int INF = 0x3f3f3f3f;

int m, n;
char a[MAX], b[MAX];
int f[MAX][MAX];

int find(char ch)
{
	if (ch == 'A')
	{
		return 1;
	}
	else if (ch == 'C')
	{
		return 2;
	}
	else if (ch == 'G')
	{
		return 3;
	}
	else 
	{
		return 4;
	}
}

int main()
{
	
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			f[i][j] = -INF;
		}
	}

	f[0][0] = 0;

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		f[i][0] = f[i - 1][0] + mapo[find(a[i])][5];
	}
	
	cin >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> b[i];
		f[0][i] = f[0][i - 1] + mapo[5][find(b[i])];
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + mapo[find(a[i])][find(b[j])]);
			f[i][j] = std::max(f[i][j], f[i - 1][j] 	+ mapo[find(a[i])][5]);
			f[i][j] = std::max(f[i][j], f[i][j - 1]		+ mapo[5][find(b[j])]);
		}
	}

	cout << f[n][m];
}
