#include <iostream>

using std::cin;
using std::cout;

long long qAns(long long a, long long b, long long p)
{
    long long base = a, ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans *= base;
            ans %= p;
        }
        base *= base;
        base %= p;
        b >>= 1;
    }
    ans %= p;
    return ans;
}

int main(int argc, char const *argv[])
{
    long long a, b, p;

    cin >> a >> b >> p;
    cout << a << '^' << b << " mod " << p << '=' << qAns(a, b, p);
    return 0;
}
