#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;

int main()
{
    double f;
    cin >> f;
    cout << std::fixed << std::setprecision(5) << 5 * (f - 32) / 9;

    return 0;
}