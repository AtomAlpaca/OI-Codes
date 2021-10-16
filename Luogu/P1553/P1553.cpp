#include <iostream>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    bool flag = false;
    std::string s;
    cin >> s;

    if (s.find('.') != std::string::npos)
    {
        int i = s.find('.');
        int j = i - 1;
        while (s[j] == '0')
        {
            --j;
        }
        if (j < 0)
        {
            cout << '0';
        }
        else
        {
            for ( ; j >= 0; --j)
            {
                cout << s[j];
            }
        }
        cout << '.';
        int len = s.length();
        j = len - 1;
        ++i;
        // while (s[j] == '0')
        // {
        //     --j;
        // }
        while (s[i] == '0')
        {
            ++i;
        }
        if (j < i)
        {
            cout << '0';
        }
        else
        {
            for ( ; j >= i; --j)
            {
                cout << s[j];
            }
        }
    }
    else if (s.find('/') != std::string::npos)
    {
        int i = s.find('/');
        int j = i - 1;
        while (s[j] == '0')
        {
            --j;
        }
        if (j < 0)
        {
            cout << '0';
        }
        else
        {
            for ( ; j >= 0; --j)
            {
                cout << s[j];
            }
        }
        cout << '/';
        int len = s.length();
        j = len - 1;
        while (s[j] == '0')
        {
            --j;
        }
        if ( j <= i)
        {
            cout << '0';
        }
        else
        {
            for ( ; j > i; --j)
            {
                cout << s[j];
            }
        }
    }
    else if (s.find('%') != std::string::npos )
    {
        int i = s.length() - 2;
        while (s[i] == '0')
        {
            --i;
        }
        if (i < 0)
        {
            cout << '0';
        }
        else
        {
            for ( ; i >= 0; --i)
            {
                cout << s[i];
            }
        }
        cout << '%';
    }
    else
    {
        if (s == "0")
        {
            cout << '0';
            return 0;
        }
        int i = s.length() - 1;
        while (s[i] == '0')
        {
            --i;
        }
        for ( ; i >= 0; --i)
        {
            cout << s[i];
        }
    }
    return 0;
}


