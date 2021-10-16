#include <iostream>

using std::cout;
using std::cin;

int main()
{
    long long n, ans = 0, sum = 0;
    
    cin >> n;

    for (long long i = 1; i <= n; ++i)
    {
        long long y = i;

        while (y % 5 == 0)
        {
            ++sum;
            y /= 5;
        }

        ans += sum;
    }

    cout << ans;
    return 0;
}