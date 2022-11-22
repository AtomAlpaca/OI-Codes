#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 3e5 + 5;

int s, m, t;
int f[MAX];

int main()
{
	cin >> m >> s >> t;

	for (int i = 1; i <= t; ++i)
	{
		if (m >= 10)
		{
			f[i] = f[i - 1] + 60;
			m -= 10;
		}
		else
		{
			f[i] = f[i - 1];
			m += 4;
		}
	}

	for (int i = 1; i <= t; ++i)
	{
		if (f[i] < f[i - 1] + 17)
		{
			f[i] = f[i - 1] + 17;
		}
		if (f[i] >= s)
		{
			cout << "Yes\n" << i;
			return 0;
		}
	}

	cout << "No\n" << f[t];
}
