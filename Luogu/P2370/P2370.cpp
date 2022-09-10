#include <iostream>

using std::cin;
using std::cout;

int f[1005], w[1005], v[1005];
int t, n, m, l, r, p, s, ans;
bool flag = false;

bool solve(int ans)
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = s; j >= w[i]; --j)
		{
			if (w[i] > ans)
			{
				break;
			}
			f[j] = std::max(f[j - w[i]] + v[i], f[j]);
		}
	}

	int k = -1;

	for (int i = 1; i <= s; ++i)
	{
		k = std::max(k, f[i]);
		f[i] = 0;
	}

	if (k >= p)
	{
		return true;
	}
	else
	{
		return false;
	}

}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> p >> s;

	for (int i = 1; i <= n; ++i)
	{
		cin >> w[i] >> v[i];
		r = std::max(r, w[i]);
	}

	l = 0, ans = -1;

	while (l <= r)
	{
		t = l + ((r - l) >> 1);
		if (!solve(t))
		{
			l = t + 1;
		}
		else
		{
			r = t - 1;
			ans = t;
		}
	}

	if (ans != -1)
	{
		cout << ans;
	}
	else
	{
		cout << "No Solution!";
	}

	return 0;
}
