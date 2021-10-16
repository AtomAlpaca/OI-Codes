#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::cin;

int main(int argc, char const *argv[])
{
    int n, m, s;
    cin >> n >> m;
    std::vector<unsigned short> nums;
    nums.push_back(100000000);
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        nums.push_back(s);
    }
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < m; ++i)
    {
        cout << nums[i] << '\n';
    }
    
    
    return 0;
}
