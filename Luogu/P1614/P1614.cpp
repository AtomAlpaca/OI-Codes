#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int n, m;
    int nums[30005];

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    if (n == m)
    {
        for (int i = 1; i < n; ++i)
        {
            nums[0] += nums[i];
        }
    }

    for (int i = 0; i < n - m; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            nums[i] += nums[i + j];
        }
    }

    std::sort(nums, nums + n - m);

    cout << nums[0];

    return 0;
}