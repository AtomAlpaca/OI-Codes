#include <iostream>
using std::cin;
using std::cout;
const int rqy = 100003;
int f[100005];

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= std::min(i, k); ++j)
        {
            f[i] += f[i - j];
            f[i] %= rqy;
        }
    }
    cout << f[n];
    return 0;
}
