#include <iostream>

using std::cin;
using std::cout;

int main()
{
    char ch;
    cin >> ch;
    cout << "  " << ch << "  " << '\n'
        << ' ' << ch << ch << ch << ' ' << '\n'
        << ch << ch << ch << ch << ch;
    return 0;
}