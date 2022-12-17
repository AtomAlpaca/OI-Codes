#include <iostream>

using std::cin;
using std::cout;

const int MAX = 105;
int l, r, m, n, T, t;

struct Node
{
	int l, r, t;
} a[MAX];

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		l = r = m;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i].t >> a[i].l >> a[i].r;
		}

		for (int i = 1; i <= n; ++i)
		{
			l -= a[i].t - a[i - 1].t;
			r += a[i].t - a[i - 1].t;
			
			if (r < a[i].l or l > a[i].r)
			{
				cout << "NO\n";
				break;
			}
			l = std::max(l, a[i].l);
			r = std::min(r, a[i].r);
			if (i == n)
			{
				cout << "YES\n";
			}
		}

	}

	return 0;
}
