#include <iostream>
using namespace std;
int main()
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    cin >> a >> b >> c >> d;
    if(d < b)
    {
        d = d + 60;
        c = c - 1;
    }
    e = c - a;
    f = d - b;
    cout << e << " " << f;
    return 0;
}