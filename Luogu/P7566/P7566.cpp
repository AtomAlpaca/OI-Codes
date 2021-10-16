#include <iostream>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int n;
    long long M = 0, C = 0, O = 0, I = 0;
    std::string str;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        if (str[0] == 'M')
        {
            ++M;
        }
        else if (str[0] == 'C')
        {
            ++C;
        }
        else if (str[0] == 'O')
        {
            ++O;
        }
        else if (str[0] == 'I')
        {
            ++I;
        }
    }
    cout << ((M * C * I) + (M * C * O) + (M * O * I) + (C * O * I));
    return 0;
}
