#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;

int main()
{
    double a, b;
    cin >> a >> b;
    cout << std::fixed << std::setprecision(3)
    << 100.0 * b / a << '%';
    return 0;
}