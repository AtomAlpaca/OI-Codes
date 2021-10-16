#include <cmath>
#include <iostream>

using std::cin;
using std::cout;

long long n, k, ans = 0;
int nums[25];

bool isPr(int num)
{
    if (num != 2 and num % 2 == 0)
    {
        return false;
    }
    else
    {
        for (int i = 2; i * i <= num; ++i)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

void search(int m,  int s, int sum)
{
    if (m == k)
    {
        if (isPr(sum) == true)
        {
            ++ans;
        }

        return ;
    }
    else
    {
        for (int i = s; i < n; ++i)
        {
            search(m + 1, i + 1, sum + nums[i]);
        }

        return ;
    }
}


int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    search(0, 0, 0);

    cout << ans;
    return 0;
}
