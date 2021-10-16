#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;

int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << std::fixed << std::setprecision(2) << double ((a * b - c * d) / (b - d));
    return 0;
}