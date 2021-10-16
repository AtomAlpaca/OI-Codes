#include <algorithm>
#include <iostream>

using std::cout;
using std::cin;

struct node
{
    int id = 0;
    int num = 0;
}n[105];;

bool isSo(node n1, node n2)
{
    if (n1.num != n2.num)
    {
        return n1.num > n2.num;
    }
    else
    {
        return n1.id < n2.id;
    }
}

int main()
{
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    

    int max = a1 + a2 + a3;
    for (int i = 0; i <= max; ++i)
    {
        n[i].id = i;
    }

    for (int i = 1; i <= a1; ++i)
    {
        for (int j = 1; j <= a2; ++j)
        {
            for (int k = 1; k <= a3; ++k)
            {
                ++n[i + j + k].num;
            }
        }
    }

    std::sort(n, n + a1 + a2 + a3, isSo);

    cout << n[0].id;

    return 0;
}