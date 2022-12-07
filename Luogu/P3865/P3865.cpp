#include <cmath>
#include <iostream>

using std::cin;
using std::cout;

const int MAX = 1e5 + 5;

int m, n, l, r;
int st[MAX][20];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;

}
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> st[i][0];
	}

	for (int i = 1; i <= 20; ++i)
	{
		const int p = (1 << i);
		for (int j = 1; j + p - 1 <= n; ++j)
		{
			st[j][i] = std::max(st[j][i - 1], st[j + (p >> 1)][i - 1]);
		}
	}

	while (m--)
	{
		cin >> l >> r;
		const int g = std::log2(r - l + 1), p = (1 << g);
		cout << std::max(st[l][g], st[r - p + 1][g]) << '\n';
	}

	return 0;
}
