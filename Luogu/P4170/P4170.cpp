#include <iostream>

using std::cin;
using std::cout;
using std::string;

const int INF = 0x3f3f3f3f;
int f[55][55];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	string str;
	cin >> str;
	const int n = str.length();

	for (int i = 0; i <= 51; ++i)
	{
		for (int j = 0; j <= 51; ++j)
		{
			f[i][j] = INF;
		}
	}

	for (int i = 0; i <= 51; ++i)
	{
		f[i][i] = 1;
	}

	for (int i = 0; i < n - 1; ++i)
	{
		if (str[i] == str[i + 1])
		{
			f[i][i + 1] = 1;
		}
		else
		{
			f[i][i + 1] = 2;
		}
	}

	for (int i = 3; i <= n; ++i)
	{
		for (int j = 0; j <= n - i + 1; ++j)
		{
			int l = j, r = j + i - 1;
			if (str[l] == str[r])
			{
				f[l][r] = std::min(f[l + 1][r], f[l][r - 1]);
			}

			for (int k = l + 1; k < r; ++k)
			{
				f[l][r] = std::min(f[l][r], f[l][k] + f[k + 1][r]);
			}
		}
	}

	cout << f[0][n - 1];

	return 0;
}
