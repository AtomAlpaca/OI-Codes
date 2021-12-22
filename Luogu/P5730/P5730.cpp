#include <iostream>

using std::cin;
using std::cout;

int T;
char nums[105];

int main()
{

    std::string strs[15][5] = 
    {
        {
            "XXX",
            "X.X",
            "X.X",
            "X.X",
            "XXX"
        },
        {
            "..X",
            "..X",
            "..X",
            "..X",
            "..X"
        },
        {
            "XXX",
            "X..",
            "XXX",
            "X..",
            "XXX"
        },
        {
            "XXX",
            "..X",
            "XXX",
            "..X",
            "XXX"
        },
        {
            "X.X",
            "X.X",
            "XXX",
            "..X",
            "..X"
        },
        {
            "XXX",
            "X..",
            "XXX",
            "..X",
            "XXX"
        },
        {
            "XXX",
            "X..",
            "XXX",
            "X.X",
            "XXX"
        },
        {
            "XXX",
            "..X",
            "..X",
            "..X",
            "..X"
        },
        {
            "XXX",
            "X.X",
            "XXX",
            "X.X",
            "XXX"
        },
        {
            "XXX",
            "X.X",
            "XXX",
            "..X",
            "XXX"
        }
    };

    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < T - 1; ++j)
        {
            cout << strs[int(nums[j] - '0')][i] << '.';
        }
        cout << strs[nums[T - 1]][i] << '\n';
    }
    return 0;
}