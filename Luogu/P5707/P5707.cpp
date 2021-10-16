#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int ans = 8 * 60;
    double s, v;
    cin >> s >> v;
    int time = std::ceil(s / v) + 10; // 时间
    ans -= time;
    if (ans > 0)
    {
        int h = ans / 60;
        int m = ans - h * 60;
        if (h < 10)
        {
            cout << 0 << h;
        }
        else
        {
            cout << h;
        }
        cout << ':';
        if (m < 10)
        {
            cout << 0 << m;
        }
        else
        {
            cout << m;
        }
    }
    else
    {
        ans += 24 * 60;
        int h = ans / 60;
        int m = ans - h * 60;
        if (h < 10)
        {
            cout << 0 << h;
        }
        else
        {
            cout << h;
        }
        cout << ':';
        if (m < 10)
        {
            cout << 0 << m;
        }
        else
        {
            cout << m;
        }
    }
    return 0;
}
