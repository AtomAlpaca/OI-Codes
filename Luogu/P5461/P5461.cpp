#include <iostream>

using std::cin;
using std::cout;

int n;
int f[1205][1205];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	cin >> n;
	const int max = 1 << n;
	f[1][max] = 1;
	for (int i = 2; i <= max; ++i)
	{
		for (int j = 1; j <= max; ++j)
		{
			f[i][j] = f[i - 1][j] ^ f[i - 1][j + 1];
		}
	}
	
	for (int i = 1; i <= max; ++i)
	{
		for (int j = 1; j <= max; ++j)
		{
			cout << f[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}

