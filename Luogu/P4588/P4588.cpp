#include <iostream>

using std::cin;
using std::cout;

long long T, op, MOD, m, Q;
long long t[400005];

void upd(int x)
{
	t[x] = t[x << 1] * t[x << 1 | 1] % MOD;
	return ;
}

void init(int l, int r, int x)
{
	t[x] = 1;

	if (l == r)
	{
		return ;
	}

	int k = l + ((r - l) >> 1);
	init(l, k, x << 1);
	init(k + 1, r, x << 1 | 1);
	upd(x);
	return ;
}

void change(int l, int r, int o, int c, int x)
{
	if (l == r)
	{
		t[x] = c;
		return ;
	}

	int k = l + ((r - l) >> 1);

	if (k >= o)
	{
		change(l, k, o, c, x << 1);
	}
	else
	{
		change(k + 1, r, o, c, x << 1 | 1);
	}

	upd(x);

	return ;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		cin >> Q >> MOD;
		init(1, Q, 1);

		for (int i = 1; i <= Q; ++i)
		{
			cin >> op >> m;
			if (op == 1)
			{
				change(1, Q, i, m, 1);
			}
			else
			{
				change(1, Q, m, 1, 1);
			}
			cout << t[1] << '\n';
		}
	}
	return 0;
}
