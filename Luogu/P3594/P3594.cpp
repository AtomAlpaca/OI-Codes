#include <iostream>

using std::cin;
using std::cout;

const int MAX = 2e6 + 5;

int n, p, d, tmp, t, h, ans;
unsigned long long s[MAX], f[MAX], q[MAX], r[MAX];

void push(long long x, long long y)
{
	while (q[t] < x and t >= h)
	{
		--t;
	}

	++t;
	q[t] = x;
	r[t] = y;
}

long long get(long long x)
{
	while (r[h] < x)
	{
		++h;
	}

	return q[h];
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> p >> d;

	for (int i = 1; i <= n; ++i)
	{
		cin >> tmp;
		s[i] = s[i - 1] + tmp;
	}

	for (int i = 1; i + d - 1 <= n; ++i)
	{
		f[i] = s[i + d - 1] - s[i - 1];
	}

	ans = d;
	int j = d;

	for (int i = 1; j <= n; ++i)
	{
		do 
		{
			++j;
			push(f[j - d + 1], j - d + 1);
			ans = std::max(ans, j - i + 1);
		} while (s[j] - s[i - 1] - get(i) <= p and j <= n);
	}

	cout << std::max(ans - 1, d);
	return 0;
}

