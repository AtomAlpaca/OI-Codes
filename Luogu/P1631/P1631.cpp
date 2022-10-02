#include <algorithm>
#include <cmath>
#include <iostream>

using std::cin;
using std::cout;

long long pa, pb, n, top = 1;
long long a[100005], b[100005], ans[1000005];

int main()
{
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		cin >> b[i];
	}

	std::sort(a + 1, a + n + 1);
	std::sort(b + 1, b + n + 1);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			ans[top] = a[i] + b[j];
			++top;

			if (i * j > n)
			{
				break;
			}
		}
	}

	std::sort(ans + 1, ans + top);

	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}

	return 0;
}
