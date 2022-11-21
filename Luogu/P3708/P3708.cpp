#include <iostream>

using std::cin;
using std::cout;

const int MAX = 1e6 + 5;

long long n;
long long f[MAX];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j * i <= n; ++j)
		{
			f[i * j] += i;
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		f[i] += f[i - 1];
	}

	for (int i = 1; i <= n; ++i)
	{
		cout << n * i - f[i] << ' ';
	}

	return 0;
}
