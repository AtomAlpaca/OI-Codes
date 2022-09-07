#include <iostream>

using std::cin;
using std::cout;

const int INF = 2 << 29;
int T, d, q, t;
int f[15][15];

void init()
{
	int mul;
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			f[i][j] = INF;
		}
	}
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			mul = i * j;
			if (f[i][mul % 10] == INF)
			{
				f[i][mul % 10] = mul;
			}
		}
	}

	return ;	
}

bool isLuck(int x, int d)
{
	while (x)
	{
		if (x % 10 == d)
		{
			return true;
		}
		x /= 10;
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	init();

	while (T--)
	{
		cin >> q >> d;

		for (int i = 1; i <= q; ++i)
		{
			cin >> t;
			if (t >= f[d][t % 10] or isLuck(t, d) or t >= 10 * d)
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}

	return 0;
}
