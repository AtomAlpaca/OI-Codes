#include <bits/stdc++.h>

using std::cin;
using std::cout;

long long T, n;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        if (n & 1)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}
