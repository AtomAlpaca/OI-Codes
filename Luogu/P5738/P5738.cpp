#include <algorithm>
#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;

int m, n, max = -1, min = 11;
double sco[105];
int nums[105][25];

int main(int argc, char const *argv[])
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> nums[i][j];
			max = std::max(max, nums[i][j]);
			min = std::min(min, nums[i][j]);
			sco[i] += nums[i][j];
		}
		sco[i] -= max + min;
		max = -1;
		min = 11;
	}

	std::sort(sco, sco + n);

	cout << std::fixed << std::setprecision(2) << sco[n - 1] / (m - 2);
	return 0;
}