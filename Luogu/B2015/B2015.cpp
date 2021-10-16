#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    double r1, r2;
    cin >> r1 >> r2;
    cout << std::fixed << std::setprecision(2) << 
        1 / (1 / r1 + 1 / r2);
    return 0;
}
