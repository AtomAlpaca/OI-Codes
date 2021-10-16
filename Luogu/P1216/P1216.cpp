#include <bits/stdc++.h>
using namespace std;
//nums[x][y][0]用于存储原始数据
//nums[x][y][1]用于存储当前最大
int nums[1005][1005][2];

int main(int argc, char const *argv[])
{
	int r;
	int ans = 0;
	cin >> r;
	for (int i = 1; i <= r; ++i)
	{
		for (int j = i; j > 0; --j)
		{
			cin >> nums[i][j][0];
		}
	}
	for (int i = 1; i <= r; ++i)
	{
		for (int j = i; j > 0; --j)
		{
			nums[i][j][1] = max(nums[i - 1][j - 1][1],nums[i - 1][j][1]) + nums[i][j][0];
		}
	}
	for (int i = 1; i <= r; ++i)
	{
		ans = max(ans,nums[r][i][1]);
	}
	cout << ans;
	return 0;
}