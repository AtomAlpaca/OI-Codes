#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 1e6 + 5;

long long p1, p2, t1, t2, n, k;
long long a[MAX], q1[MAX], q2[MAX], r1[MAX], r2[MAX];
std::pair <int, int> ans[MAX];

void push(int x, int y)
{
	while (q1[p1] <= x and p1 >= t1)
	{
		--p1;
	}

	while (q2[p2] >= x and p2 >= t2)
	{
		--p2;
	}

	++p1, ++p2;
	q1[p1] = x;
	q2[p2] = x;
	r1[p1] = y;
	r2[p2] = y;
	return ;
}

std::pair <int, int> get(int x)
{
	while (r1[t1] < x)
	{
		++t1;
	}

	while (r2[t2] < x)
	{
		++t2;
	}

	return std::make_pair(q1[t1], q2[t2]);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for (int i = 1; i < k; ++i)
	{
		push(a[i], i);
	}

	for (int i = k; i <= n; ++i)
	{
		push(a[i], i);
		ans[i] = get(i - k + 1);
	}
	for (int i = k; i <= n; ++i)
	{
		cout << ans[i].second << ' ';
	}	

	cout << '\n';
	
	for (int i = k; i <= n; ++i)
	{
		cout << ans[i].first << ' ';
	}
	return 0;
}

