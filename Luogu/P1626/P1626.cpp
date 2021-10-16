#include <algorithm>
#include <cmath>
#include <iostream>

using std::cout;
using std::cin;

int main()
{
    int n, k;
    int nums[100005];

    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    std::sort(nums, nums + n);

    for (int i = 0; i < n - 1; ++i)
    {
        nums[i] = std::abs(nums[i] - nums[i + 1]);
    }

    std::sort(nums, nums + n - 1);
    n = 0;

    for (int i = 0; i < k; ++i)
    {
        n += nums[i];
    }

    cout << n;
    
    return 0;
}