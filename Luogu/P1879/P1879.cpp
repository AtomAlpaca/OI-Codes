#include <iostream>

using std::cin;
using std::cout;

const int MOD = 100000000;
const int MAX = (1 << 13) - 1;
const int INF = 0x3f3f3f3f;

int m, n, s;
long long ans;

bool able[MAX];
int g[15];
int f[15][MAX];

void init()
{
	for (int i = 0; i <= (1 << n) - 1; ++i)
	{
		if (!(i & (i >> 1)) and !(i & (i << 1)))
		{
			able[i] = true;
			if ((g[1] & i) == i)
			{
				f[1][i] = 1;
			}
		}
		
	}
	return ;
}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> m >> n;

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> s;
			g[i] |= s;
			g[i] <<= 1;
		}
		g[i] >>= 1;
	}

	init();

	for (int i = 1; i < m; ++i)
	{
		for (int j = 0; j <= ((1 << n) - 1); ++j)
		{
			if (able[j] and (j & g[i]) == j)
			{
				//cout << j << ' ' << g[i] << '\n';
				for (int k = 0; k <= ((1 << n) - 1); ++k)
				{
					if ((k & j) == 0 and (k & g[i + 1]) == k and able[k])
					{
						f[i + 1][k] += f[i][j];
					}
				}
			}
		}
	}

	for (int i = 0; i <= ((1 << n) - 1); ++i)
	{
		ans += f[m][i];
		ans %= MOD;
	}

	cout << ans % MOD;
}


