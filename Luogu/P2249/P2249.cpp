#include <iostream>

using std::cin;
using std::cout;

long long n, m, l, r, f, mid;
long long a[1000005];

void find(long long x)
{
	l = 1, r = n;
	while (l < r)
	{
		mid = l + ((r - l) >> 1);
		if (a[mid] >= x)
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	if (a[l] == x)
	{
		cout << l << ' ';
	}
	else
	{
		cout << -1 << ' ';
	}
	
	return ;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	
	while (m--)
	{
		cin >> f;
		find(f);
	}
	
	return 0;
}

