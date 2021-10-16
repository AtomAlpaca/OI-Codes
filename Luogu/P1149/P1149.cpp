#include <iostream>

using std::cin;
using std::cout;

int n, ans = 0;

const int NUMS[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int getAns(int num)
{
    int a = 0;
    a += NUMS[num % 10];
    while (num >= 10)
    {
        num /= 10;
        a += NUMS[num % 10];
    }

    return a;
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    n -= 4;
    //cout << getAns(10) << '\n';
    for (int i = 0; i <= 1000; ++i)
    {
        for (int j = 0; j <= 1000; ++j)
        {
            if (getAns(i) + getAns(j) + getAns(i + j) == n)
            {
                ++ans;
                //cout << i << '+' << j << '=' << i + j << '\n';
            }
        }
    }
    cout << ans;
    return 0;
}
