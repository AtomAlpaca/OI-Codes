#include <cmath>
#include <iostream>

using std::cout;
using std::cin;

int main(int argc, char const *argv[])
{
    int n;
    int ans = 0;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        ans += std::floor(n / i);
    }

    cout << ans;
    return 0;
}
