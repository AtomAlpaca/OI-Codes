#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;

int n, k, now = 0;
int nums[10005], dp[10005];

struct Task
{
	int start, tim;
} task[10005];

bool Cmp(Task T1, Task T2)
{
	return T1.start > T2.start;
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < k; ++i)
	{
		cin >> task[i].start >> task[i].tim;
		++nums[task[i].start];
	}

	std::sort(task, task + k, Cmp);

	for (int i = n; i >= 1; --i)
	{
		if (nums[i] == 0)
		{
			dp[i] = dp[i + 1] + 1;
		}
		else
		{
			while (task[now].start == i)
			{
				dp[i] = std::max(dp[i], dp[i + task[now].tim]);
				++now;
			}
		}
	}

	cout << dp[1];
	return 0;
}