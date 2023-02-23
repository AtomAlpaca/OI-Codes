#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 3e5 + 5;

std::string str;
// f[i] = min(f[j] + 1), s(i) - s(j) >= 0
// f[i] = min(f[j]), s(i) - s(j) < 0
long long cnt, n, k;
long long a[MAX], s[MAX], f[MAX];

void pu(int x)
{
	while (x != 1)
	{
		if (f[a[x]] < f[a[x >> 1]] or (f[a[x]] == f[a[x >> 1]] and s[a[x]] > s[a[x >> 1]]))
		{
			std::swap(a[x], a[x >> 1]);
			x >>= 1;
		}
		else
		{
			break;
		}
	}
	return ;
}

void pd(int x)
{
	while (true)
	{
		int t = x;
		if ((f[a[x << 1]] < f[a[t]] or (f[a[x << 1]] == f[a[t]] and s[a[x << 1]] > s[a[t]])) and (x << 1) <= cnt)
		{
			t = x << 1;
		}
		if ((f[a[x << 1 | 1]] < f[a[t]] or (f[a[x << 1 | 1]] == f[a[t]] and s[a[x << 1 | 1]] > s[a[t]])) and (x << 1 | 1) <= cnt)
		{
			t = x << 1 | 1;
		}
		if (t == x)
		{
			break;
		}
		std::swap(a[x], a[t]);
		x = t;
	}
	return ;
}

int top()
{
	return a[1];
}

void pop()
{
	std::swap(a[1], a[cnt]);
	--cnt;
	pd(1);
}

void add(int x)
{
	++cnt;
	a[cnt] = x;
	pu(cnt);
}

int main()
{
	cin >> n >> k;
	cin >> str;
	for (int i = 1; i <= n; ++i)
	{
		if (str[i - 1] == 'H')
		{
			s[i] = s[i - 1] - 1;
		}
		else
		{
			s[i] = s[i - 1] + 1;
		}
	}

	f[0] = 0;
	
	add(0);
	for (int i = 1; i <= n; ++i)
	{
		while (top() < i - k)
		{
			pop();
		}
		int j = top();
		if (s[i] - s[j] >= 0)
		{
			f[i] = f[j] + 1;
		}
		else
		{
			f[i] = f[j];
		}
		add(i);
	}
	cout << f[n];
}

