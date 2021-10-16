#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;

int main()
{
    double a, b;
    cin >> a >> b;
    cout << std::fixed << std::setprecision(9)
    << a / b;
    return 0;
}