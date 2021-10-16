#include <iostream>
#include <cmath>
#include <algorithm>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    //int m = -10000000;

    int * n = new int;
    cin >> *n;

    int nums[*n + 1] = {0};
    int ans [*n + 1] = {0};
    int m = -99999999;
    for (int i = 1; i <= *n; ++i)
    {
        cin >> nums[i];
        ans[i] = std::max(ans[i - 1] + nums[i], nums[i]);
        m = std::max(m, ans[i]);
    }

    cout << m;
    delete n;
    return 0;
}
