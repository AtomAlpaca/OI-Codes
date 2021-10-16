#include <iostream>

using std::cout;
using std::cin;

int main(int argc, char const *argv[])
{
    int * n = new int;
    cin >> *n;
    
    int * nums = new int[*n + 1];

    for (int i = 0; i <= *n; ++i)
    {
        cin >> nums[i];
    }

    if (nums[0] != 0)
    {
        if (nums[0] < 0)
        {
            if (nums[0] == -1)
            {
                cout << '-' << "x^" << *n;
            }
            else
            {
                cout << nums[0] << 'x' << '^' << *n;
            }
        }
        else
        {
            if (nums[0] == 1)
            {
                cout << "x^" << *n;
            }
            
            else
            {
                cout << nums[0] << 'x' << '^' << *n;
            }
        }
    }

    for (int i = 1; i < *n - 1; ++i)
    {
        if (nums[i] != 0)
        {
            if (nums[i] < 0)
            {
                if (nums[i] != -1)
                {
                    cout << nums[i];
                }
                else
                {
                    cout << '-';
                }
            }
            else
            {
                if (nums[i] != 1)
                {
                    cout << '+' << nums[i];
                }
                else
                {
                    cout << '+';
                }
            }
            cout << 'x' << '^' << (*n - i);
        }
    }

    if (nums[*n - 1] != 0)
    {
        if (nums[*n - 1] > 0)
        {
            if (nums[*n - 1] == 1)
            {
                cout << '+' << 'x';
            }
            else
            {
                cout << '+' << nums[*n - 1] << 'x';
            }
        }
        else
        {
            if (nums[*n - 1] == -1)
            {
                cout << '-' << 'x';
            }
            else
            {
                cout << nums[*n - 1] << 'x';
            }
        }
    }


    if (nums[*n] != 0)
    {
        if (nums[*n] > 0)
        {
            cout << '+' << nums[*n];
        }
        else
        {
            cout << nums[*n];
        }
    }

    delete n;
    delete [] nums;

    return 0;
}
