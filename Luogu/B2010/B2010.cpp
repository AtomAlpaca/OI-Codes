#include <iostream>

using std::cin;
using std::cout;

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << a / b << ' ' << a - ((a / b) * b);
    return 0;
}