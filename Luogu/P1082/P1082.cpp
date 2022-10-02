#include <iostream>

using std::cin;
using std::cout;

int m, n, ans, ans2;

int exgcd(int a, int b, int & x, int & y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - ((a / b) * y);
    return d;
}

void sol(int a, int b, int c, int & x, int & y)
{
    int d = exgcd(a, b, x, y);
    x = x / d;
    y = y / d;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    cin >> m >> n;

    sol(m, n, 1, ans, ans2);
    cout << (ans % n + n) % n;

    return 0;
}
