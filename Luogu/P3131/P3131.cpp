#include <iostream>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int sum;
    int * n = new int;
    cin >> *n;

    long long * nums = new long long[*n + 2];

    for (int i = 1; i <= *n; ++i)
    {
        cin >> sum;
        nums[i] = nums[i - 1] + sum;
    }

    for (int i = *n - 1; i > 0; --i)
    {
        for (int j = 1; j  + i < *n; ++j)
        {
            if ((nums[i + j] - nums[j]) % 7 == 0)
            {
                cout << i;
                delete n;
                delete [] nums;
                return 0;
            }
        }
    }
    cout << '0';
    delete n;
    delete [] nums;
    return 0;
    return 0;
}
