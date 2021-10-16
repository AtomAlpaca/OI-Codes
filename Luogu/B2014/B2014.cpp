#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    const double PI = 3.14159;
    double r;
    cin >> r;
    cout << std::fixed << std::setprecision(4) << r * 2 << ' ' << r * 2 * PI << ' ' << r * r * PI;
    return 0;
}
