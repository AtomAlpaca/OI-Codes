#include <iostream>

using std::cin;
using std::cout;

int n, T, sta[100005], pop[100005], pus[100005], ptr, tot, cnt;

void cle(int x)
{
	for (int i = 0; i <= x; ++i)
	{
		sta[i] = 0;
	}
	tot = cnt = 0;
	ptr = 1;
}

void solve()
{
	for (int i = 1; i <= n; ++i)
	{
		++tot, ++cnt;
		sta[tot] = pus[i];
		while (sta[tot] == pop[ptr] and ptr != n + 1)
		{
			--tot;
			++ptr;
		}
	}
	if (ptr == n + 1)
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;
	
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> pus[i];
		}

		for (int i = 1; i <= n; ++i)
		{
			cin >> pop[i];
		}
		cle(n);
		solve();
	}

	return 0;
}

