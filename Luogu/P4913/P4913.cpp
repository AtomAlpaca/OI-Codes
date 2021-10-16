#include <bits/stdc++.h>
using namespace std;

int ans = 0;

struct node
{
	int lChild;
	int rChild;
}nums[100000];


void findAns(int num,int deep)
{
	if (num == 0)
	{
		return;
	}
	ans = max(ans,deep);
		findAns(nums[num].lChild,deep + 1);
		findAns(nums[num].rChild,deep + 1);
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> nums[i].lChild >> nums[i].rChild;
	}
	findAns(1,1);
	cout << ans;
	return 0;
}