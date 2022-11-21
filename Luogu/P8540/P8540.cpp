#include <iostream>

using std::cin;
using std::cout;

long long a, b, c;

long long lowbit(long long x)
{
	if (x == 0)
	{
		return 0;
	}
	long long ans = 1;
	while (!(x & 1))
	{
		x >>= 1;
		ans <<= 1;
	}
	return ans;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> a >> b >> c;

	if (!(c & 1))
	{
		if (!(a & 1))
		{
			cout << lowbit(c);
		}
		else
		{
			cout << 1;
		}
	}
	else
	{
		if (!(a & 1))
		{
			if (!(b & 1))
			{
				cout << lowbit(c - 1);
			}
			else
			{
				cout << 1;
			}
		}
		else
		{
			if (!(b & 1))
			{
				cout << 1;
			}
			else
			{
				cout << lowbit(c - 1);
			}
		}
	}

	return 0;
}
