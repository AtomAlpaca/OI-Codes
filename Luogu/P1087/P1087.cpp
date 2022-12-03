#include <iostream>

using std::cin;
using std::cout;

const int MAX = (1 << 10) + 5;

int n;
std::string str;
int a[MAX], sum[MAX];

void solve(int x, int y)
{
	if (x == y)
	{
		if (a[x] == 0)
		{
			cout << 'B';
		}
		else
		{
			cout << 'I';
		}
		return ;
	}
	int k = (x + y) / 2;
	solve(x, k);
	solve(k + 1, y);

	if (sum[y] - sum[x - 1] == 0)
	{
		cout << 'B';
	}
	else if (sum[y] - sum[x - 1] == y - x + 1)
	{
		cout << 'I';
	}
	else
	{
		cout << 'F';
	}
}

int main()
{
	cin >> n >> str;
	for (int i = 1; i <= (1 << n); ++i)
	{
		a[i] = str[i - 1] - '0';
		sum[i] = sum[i - 1] + a[i];
	}

	solve(1, 1 << n);

	return 0;
}
