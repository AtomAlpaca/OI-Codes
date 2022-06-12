#include <iostream>

using std::cin;
using std::cout;

long long n, a[15], b[15], m[15], c[15], ans;
long long N = 1;

void exgcd(long long a, long long b, long long & x, long long & y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return ;
	}
	exgcd(b, a % b, x, y);
	long long t = x;
	x = y;
	y = t - ((a / b) * y);
	return ;
}

void sol()
{
	for (int i = 1; i <= n; ++i)
	{
		N *= a[i];
	}
	
	for (int i = 1; i <= n; ++i)
	{
		m[i] = N / a[i];
		long long x = 0, y = 0;
		exgcd(m[i], a[i], x, y);
		ans += (b[i] * m[i] * x) % N;
	}

	cout << (ans % N + N) % N;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i];
	}

	sol();
	return 0;
}
