#include <iostream>

using std::cin;
using std::cout;

const long long INF = 1e9 + 7;

long long n, k, l, r, mid, min = INF;
long long a[1000005];

int ans(int x)
{
	int t = 0;
	for (int i = 1; i <= n; ++i)
	{
		t += a[i] / x;
	}
	return t;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		min = std::min(min, a[i]);
	}
	
	l = 1, r = min << 1;
	
	while (l <= r)
	{
		mid = l + ((r - l) >> 1);
		if (ans(mid) > k)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	
	
	while (ans(mid) >= k)
	{
		++mid;
	}
	
	cout << mid - 1;
	
	return 0;
}
