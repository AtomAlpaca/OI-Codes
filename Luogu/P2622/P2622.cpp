#include <iostream>

using std::cin;
using std::cout;

const int MAX = 105;
const int INF = 0x3f3f3f3f;

int n, m;
long long f[2005];
int a[105][15];

void init()
{
	for (int i = 0; i < 2005; ++i)
	{
		f[i] = INF;
	}
	return ;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	init();

	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> a[i][j];
		}
	}

	f[(1 << n) - 1] = 0;

	for (int i = (1 << n) - 1; i >= 0; --i)
	{
		for (int j = 1; j <= m; ++j)
		{
			int st = i;
			for (int k = 1; k <= n; ++k)
			{
				if (a[j][k] == 1)
				{
					if (i & (1 << (k - 1)))
					{
						st ^= (1 << (k - 1));
					}
				}
				else if (a[j][k] == -1)
				{
					if (!(i & (1 << (k - 1))))
					{
						st |= (1 << (k - 1));
					}
				}
			}
			f[st] = std::min(f[st], f[i] + 1);
		}
	}

	if (f[0] == INF)
	{
		cout << -1;
	}
	else
	{
		cout << f[0];
	}
}


