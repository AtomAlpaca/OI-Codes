#include <cmath>
#include <iostream>

using std::cin;
using std::cout;

const int MAX = 1e5 + 5;

int m, n;
int s[MAX][21];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		cin >> s[i][0];
	}

	for (int j = 1; j <= 21; ++j)
	{
		for (int i = 1; i + (1 << j) - 1 <= n; ++i)
		{
			s[i][j] = std::min(s[i][j - 1], s[i + (1 << (j - 1))][j - 1]);
		}
	}

	const int g = std::log2(m);

	for (int i = 1; i <= n - m + 1; ++i)
	{
		cout << std::min(s[i][g], s[m + i - (1 << g)][g]) << '\n';
	}

	return 0;
}
