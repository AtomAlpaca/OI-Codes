#include <iostream>

using std::cin;
using std::cout;

int count, ans, num, n;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    while (n--)
    {
        cin >> num;
        if (ans == num)
        {
            ++count;
        }
        if (count == 0)
        {
            count = 1;
            ans = num;
        }
        if (ans != num)
        {
            --count;

        }
    }
    cout << ans;
    return 0;
}