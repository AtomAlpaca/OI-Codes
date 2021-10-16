#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int nums[3];
    
    for (int i = 0; i < 3; ++i)
    {
        cin >> nums[i];
    }

    cout << nums[1];
    return 0;
}