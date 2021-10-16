#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double num;
    int i;
    cin >> num >> i;
    cout << fixed << setprecision(3) << num / i << endl << i * 2;
    return 0;
}