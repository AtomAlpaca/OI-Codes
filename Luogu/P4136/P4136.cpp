#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int num = 1;
    while (true)
    {
        cin >> num;
        if (num % 2 != 0)
        {
            cout << "Bob\n";
        }
        else if (num == 0)
        {
            break;
        }
        else
        {
            cout << "Alice\n";
        }
    }
    return 0;
}