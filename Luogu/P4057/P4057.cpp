#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;

using std::__gcd;

int main()
{
    long long a, b, c;
    long long gcd1, gcd2, lcm1, lcm2;

    cin >> a >> b >> c;

    gcd1 = __gcd(a, b);
    lcm1 = a * b / gcd1;
    gcd2 = __gcd(lcm1, c);
    lcm2 = lcm1 * c / gcd2;

    cout << lcm2;
}
