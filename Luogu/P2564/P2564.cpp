#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 1e6 + 5;
const int INF = 0x3f3f3f3f;
struct N
{
	int x, c;
} a[MAX];

int n, k, pos, l, r, cnt, ans = INF, j, num;
int b[65];
bool cmp(N n1, N n2)
{
	return n1.x < n2.x;
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= k; ++i)
	{
		cin >> j;
		while (j--)
		{
			cin >> pos;
			++num;
			a[num].x = pos;
			a[num].c = i;
		}
	}

	std::sort(a + 1, a + n + 1, cmp);

	l = r = 0;
	cnt = 1;
	b[0] = 1;
	while (true)
	{
		--b[a[l].c];
		if (b[a[l].c] == 0)
		{
			--cnt;
		}
		++l;
		while (cnt != k and r != n)
		{
			++r;
			++b[a[r].c];
			if (b[a[r].c] == 1)
			{
				++cnt;
			}
		}
		if (cnt != k)
		{
			break;
		}
		ans = std::min(ans, a[r].x - a[l].x);
		//cout << ans;
	}
	cout << ans;
	return 0;
}

