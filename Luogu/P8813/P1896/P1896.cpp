#include <iostream>

using std::cin;
using std::cout;

const int MAX = (1 << 11) - 1;
const int INF = 0x3f3f3f3f;

int n, c;
long long ans;
int num[MAX];
bool able[MAX];
long long f[11][121][MAX + 55];

inline int getn(int x)
{
	if (x == 0)
	{
		return 0;
	}
	if (num[x])
	{
		return num[x];
	}
	int p = 0;
	while (x)
	{
		p += (x & 1);
		x >>= 1;
	}
	num[x] = p;
	return p;
}

void init()
{
	for (int i = 0; i <= (1 << n) - 1; ++i)
	{
		if (!((i << 1) & i) and !((i >> 1) & i))
		{
			able[i] = true;
			f[1][getn(i)][i] = 1;
		}
	}
	return ;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> c;

	init();
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= (1 << n) - 1; ++j)
		{
			if (able[j])
			{
				for (int l = 0; l <= c; ++l)
				{
					if (l >= getn(j))
					{	
						for (int k = 0; k <= (1 << n) - 1; ++k)
						{
							if (!(j & k) and !(j & (k << 1)) and !(j & (k >> 1)) and able[k])
							{
								f[i + 1][l + getn(k)][k] += f[i][l][j];
							}
						}
					}
				}
			}
		}
	}

	for (int i = 0; i <= (1 << n) - 1; ++i)
	{
		//cout << f[n][c][i] << ' ';
		ans += f[n][c][i];
	}

	cout << ans;
}


