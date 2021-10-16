#include <bits/stdc++.h>
using namespace std;

struct gold
{
	double nums;
	double money;
	double pay;
};

bool isSort(gold g1,gold g2)
{
	if (g1.pay > g2.pay)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(int argc, char const *argv[])
{
	int n,t;
	cin >> n >> t;
	gold q[101];
	for (int i = 0; i < n; ++i)
	{
		cin >> q[i].nums >> q[i].money;
		q[i].pay = q[i].money / q[i].nums;
	}
	sort(q,q + n,isSort);
	double ans = 0;
	int sum = 0,bac = 0;
	for (int i = 0; i < n; ++i)
	{
		if (t >= q[sum].nums)
		{
			ans += q[sum].money;
		}
		else
		{
			ans += t * q[sum].pay * 1.0;
			break;
		}
		t -= q[sum].nums;
		++sum;
	}
	printf("%.2f",ans);
	return 0;
}