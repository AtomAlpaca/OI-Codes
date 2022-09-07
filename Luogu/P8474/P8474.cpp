#include <iostream>

using std::cin;
using std::cout;

const long long MOD = 1e9 + 7;
long long n;
long long pwr[10000005], f[10000005];

void init()
{
	pwr[0] = 1;
	pwr[1] = 2;
	for (int i = 2; i <= 10000005; ++i)
	{
		pwr[i] = pwr[i - 1] * 2 % MOD;
	}

	return;
}

long long solve(int x)
{
	f[1] = 1;
	f[2] = 3;
	for (int i = 3; i <= x; ++i)
	{
		f[i] = f[i - 1] * (pwr[i] - 1) % MOD;
	}
	return f[x];
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	init();
	cin >> n;
	cout << solve(n);

	return 0;
}
