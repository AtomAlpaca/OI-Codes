#include <iostream>

using std::cin;
using std::cout;

int n, a[100005], l, r, ans;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if (a[i] == 1)
		{
			++ans;
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (a[i] == 1)
		{
			l = i;
			break;
		}
	}

	for (int i = n; i >= 1; --i)
	{
		if (a[i] == 1)
		{
			r = i;
			break;
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (a[i] == 2)
		{
			if (i < l)
			{
				++ans;
			}
			break;
		}
	}

	for (int i = n; i >= 1; --i)
	{
		if (a[i] == 3)
		{
			if (i > r)
			{
				++ans;
			}
			break;
		}
	}

	cout << ans;
	return 0;
}
