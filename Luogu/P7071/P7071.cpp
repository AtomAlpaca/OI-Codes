#include <iostream>

using std::cin;
using std::cout;

int n, now, tail;
int ans[1005];

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	if (n & 1)
	{
		cout << -1;
		return 0;
	}

	now = 0;

	while ((2 << now) <= n)
	{
		if (n & (2 << now))
		{
			ans[tail] = (2 << now);
			++tail;
		}
		++now;
	}

	for (int i = tail - 1; i > 0; --i)
	{
		cout << ans[i] << ' ';
	}

	cout << ans[0];
	return 0;
}