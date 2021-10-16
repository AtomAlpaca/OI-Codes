#include <cmath>
#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int a, b, ans = 0;

    cin >> a >> b;

    for (int i = a; i <= b; ++i)
    {
        if (std::abs(i) % 2 == 1 or i % 4 == 0)
        {
            ++ans;
        }
    }
    
    cout << ans;
    
    return 0;
}