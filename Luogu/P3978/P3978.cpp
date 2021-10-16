#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;

double n;

int main()
{
    cin >> n;
    cout << std::fixed << std::setprecision(12) << n * (n + 1) / (2 * (2 * n - 1));
    return 0;
}