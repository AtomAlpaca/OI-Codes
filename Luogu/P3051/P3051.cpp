#include <bits/stdc++.h>

using std::cin;
using std::cout;
// a_1 + x_n - x_1 = b_1
// x_1 = a_1 - b_1 + x_n
// x_2 = a_2 - b_2 + x_1
// 	   = a_2 + a_1 - b_2 - b_1 + x_n
const int MAX = 100005;

long long n, m, ans;
long long a[MAX], b[MAX], c[MAX], sum[MAX];

bool cmp(int a, int b)
{
	return a < b;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i];
		c[i] = a[i] - b[i];
		sum[i] = sum[i - 1] + c[i];
	}

	std::sort(sum + 1, sum + n + 1, cmp);
	m = sum[(n >> 1) + 1];

	for (int i = 1; i <= n; ++i)
	{
		ans += std::abs(m - sum[i]);
	}

	cout << ans;

	return 0;
}

