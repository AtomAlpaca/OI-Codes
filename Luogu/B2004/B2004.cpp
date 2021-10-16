#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;

int main()
{
    int nums[3];
    
    for (int i = 0; i < 3; ++i)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < 3; ++i)
    {
        cout << std::setw(8) << nums[i] << ' ';
    }
    return 0;
}