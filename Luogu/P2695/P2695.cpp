#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int ans = 0;
	int * n = new int;
	int * m = new int;
	cin >> *n >> *m;
	int head[*n];
	int pers[*m];
	for (int i = 0; i < *n; ++i)
	{
		cin >> head[i];
	}
	for (int i = 0; i < *m; ++i)
	{
		cin >> pers[i];
	}
	if (*n > *m)
	{
		cout << "you died!";
		delete n;
		delete m;
		return 0;
	}
	sort(head,head + *n);
	sort(pers,pers + *m);
	int j = 0;
	for (int i = 0; i < *n; ++i)
	{
		while (head[i] > pers[j])
		{
			++j;
		}
		ans += pers[j];
		if (j > *m and i - 1 != *n)
		{
			cout << "you died!";
			delete n;
			delete m;
			return 0;
		}
		++j;
	}
	cout << ans;
	delete n;
	delete m;
	return 0;
}