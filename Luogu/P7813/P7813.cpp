#include <iostream>

using std::cin;
using std::cout;

const long long MOD = 1e9 + 7;
long long T, N, K, ans;

long long getNum(long long n, long long x)
{
	return (x * ((n * (n + 1)) / 2 % MOD) - x * (x - 1) / 2 % MOD);
}

int main(int argc, char const *argv[])
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;
	while (T != 0)
	{
		cin >> N >> K;
		ans = getNum(N - 1, K / 2) + getNum(N, (K - (K / 2)));
		cout << ans % MOD << '\n';
		--T;
	}
	return 0;
}