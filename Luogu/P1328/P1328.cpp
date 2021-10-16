#include <iostream>

using std::cout;
using std::cin;

int main(int argc, char const *argv[])
{
    int time;
    int lenA, lenB;

    int numsA[205], numsB[205];

    cin >> time >> lenA >> lenB;

    for (int i = 0; i < lenA; ++i)
    {
        cin >> numsA[i];
    }

    for (int i = 0; i < lenB; i++)
    {
        cin >> numsB[i];
    }
    
    int ansA = 0, ansB = 0;

    for (int i = 0; i < time; ++i)
    {
        if (numsA[i % lenA] == numsB[i % lenB])
        {
            continue;
        }
        else if (numsA[i % lenA] == 0)
        {
            if (numsB[i % lenB] == 2 or numsB[i % lenB] == 3)
            {
                ++ansA;
            }
            else if (numsB[i % lenB] == 1 or numsB[i % lenB] == 4)
            {
                ++ansB;
            }
            
        }
        else if (numsA[i % lenA] == 1)
        {
            if (numsB[i % lenB] == 0 or numsB[i % lenB] == 3)
            {
                ++ansA;
            }
            else if (numsB[i % lenB] == 2 or numsB[i % lenB] == 4)
            {
                ++ansB;
            }
            
        }
        else if (numsA[i % lenA] == 2)
        {
            if (numsB[i % lenB] == 1 or numsB[i % lenB] == 4)
            {
                ++ansA;
            }
            else if (numsB[i % lenB] == 0 or numsB[i % lenB] == 3)
            {
                ++ansB;
            }
            
        }
        else if (numsA[i % lenA] == 3)
        {
            if (numsB[i % lenB] == 2 or numsB[i % lenB] == 4)
            {
                ++ansA;
            }
            else if (numsB[i % lenB] == 0 or numsB[i % lenB] == 1)
            {
                ++ansB;
            }
            
        }
        else if (numsA[i % lenA] == 4)
        {
            if (numsB[i % lenB] == 0 or numsB[i % lenB] == 1)
            {
                ++ansA;
            }
            else if (numsB[i % lenB] == 2 or numsB[i % lenB] == 3)
            {
                ++ansB;
            }
            
        }
    }
    cout << ansA << ' ' << ansB;
    return 0;
}
