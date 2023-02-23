#include <iostream>

using std::cin;
using std::cout;

const long long MOD = 1e9 + 7;
const int MAX = 1e6 + 5;


long long T, n, m;
long long mul[MAX], d[MAX];

long long pow(long long x, long long y)
{
	long long tmp = x;
	--y;
	while (y)
	{
		if (y & 1)
		{
			tmp = (tmp * x) % MOD;
		}
		x = (x * x) % MOD;
		y >>= 1;
	}
	return tmp;
}

long long inv(long long x)
{
	return pow(x, MOD - 2);
}

long long C(long long x, long long y)
{
	return (((mul[x] * inv(mul[y])) % MOD) * inv(mul[x - y])) % MOD;
}

void init()
{
	mul[0] = 1;
	d[0] = 1;
	d[1] = 0;
	d[2] = 1;
	for (int i = 1; i < MAX - 3; ++i)
	{
		mul[i] = (mul[i - 1] * i) % MOD;
	}
	
	for (int i = 3; i < MAX - 3; ++i)
	{
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]) % MOD;
	}
	return;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	init();

	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		cout << C(n, m) * d[n - m] % MOD << '\n';
	}

}

