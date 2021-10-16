#include <bits/stdc++.h>
using namespace std;

struct cow
{
	int money;
	int num;
};

int main(int argc, char const *argv[])
{
	int * n = new int;
	int m,ans = 0;
	cin >> m >> *n;
	cow c[*n];
	for (int i = 0; i < *n; ++i)
	{
		cin >> c[i].money >> c[i].num;
	}
	sort(c,c + *n,[](cow c1,cow c2){
		if (c1.money != c2.money)
		{
			return c1.money < c2.money ? true : false;
		}
		else
		{
			return c1.num > c2.num ? true : false;
		}
	});
	int sum = 0;
	while (m > 0)
	{
		--m;
		--c[sum].num;
		ans += c[sum].money;
		if (c[sum].num == 0)
		{
			++sum;
		}
	}
	cout << ans;
	delete n;
	return 0;
}