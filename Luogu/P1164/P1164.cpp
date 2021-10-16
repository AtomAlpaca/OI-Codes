#include <iostream>

using std::cout;
using std::cin;

int n, m;
int a[105], f[10005];

int main(int argc, char const *argv[])
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    f[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = m; j >= a[i]; --j)
        {
            f[j] = f[j] + f[j - a[i]];
        }
    }

    cout << f[m];
    
    
    return 0;
}
