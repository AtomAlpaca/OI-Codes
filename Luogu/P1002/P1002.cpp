#include <iostream>

using std::cout;
using std::cin;

const int MOVEX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int MOVEY[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

long long nums[25][25] = { 0 };
bool flags[25][25] = { false };

int main(int argc, char const *argv[])
{
    int a, b;
    int x, y;

    cin >> a >> b >> x >> y;

    a += 2, b += 2, x += 2, y += 2;

    nums[2][1] = 1;
    flags[x][y] = true;

    for (int i = 0; i < 8; i++)
    {
        flags[x + MOVEX[i]][y + MOVEY[i]] = true;
    }
    
    for (int i = 2; i <= a; i++)
    {
        for (int j = 2; j <= b; j++)
        {
            if (flags[i][j] == false)
            {
                nums[i][j] = nums[i - 1][j] + nums[i][j - 1];
            }
            else
            {
                nums[i][j] = 0;
            }
        }
        
    }
    
    cout << nums[a][b];

    return 0;
}
