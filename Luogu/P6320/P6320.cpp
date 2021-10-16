
#include <iostream>

using std::cin;
using std::cout;

int n, w, h, len, l;

int main()
{
    cin >> n >> w >> h;
    
    len = w * w + h * h;
    for (int i = 0; i < n; ++i)
    {
        cin >> l;
        if (l * l <= len)
        {
            cout << "DA\n";
        }
        else
        {
            cout << "NE\n";
        }
    }
    
    return 0;
}