#include <cstring>
#include <iostream>

using std::cin;
using std::cout;

int nums[28];
int max;

int main(int argc, char const *argv[])
{
    cin.tie(0);
    cout.tie(0);
    char str[100];

    for (int i = 0; i < 4; ++i)
    {
        gets(str);
        for (int j = 0, len = strlen(str); j < len; ++j)
        {
            if (str[j] >= 'A' and str[j] <= 'Z')
            {
                ++nums[int(str[j] - 'A')];
            }
        }
    }

    for (int i = 0; i < 26; ++i)
    {
        max = std::max(max, nums[i]);
    }

    for (int i = max - 1; i >= 0; --i)
    {
        for (int j = 0; j < 27; ++j)
        {
            if (nums[j] > i)
            {
                cout << '*';
            }
            else
            {
                cout << ' ';
            }
            if (j != 26)
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    return 0;
}
