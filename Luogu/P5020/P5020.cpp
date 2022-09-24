#include <iostream>

using std::cin;
using std::cout;

int T, f[25015], n, m, a[105];

void solve()
{
	cin >> n;
	m = n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		f[a[i]] = 1;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = a[i]; j <= 25005; ++j)
		{
			f[j] += f[j - a[i]];
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (f[a[i]] != 1)
		{
			--m;
		}
	}

	cout << m << '\n';

	return ;
}

void clean()
{
	for (int i = 0; i <= 25005; ++i)
	{
		f[i] = 0;
	}
	return ;
}

int main()
{

	cin >> T;
	while (T--)
	{
		solve();
		clean();
	}
	return 0;
}
