#include <iostream>

using std::cin;
using std::cout;

int nums[100001];

void qSort(int left, int right)
{
    const int MID = nums[(left + right) / 2];
    const int LEFT = left;
    const int RIGHT = right;
    do {
        while (nums[left] < MID)
        {
            ++left;
        }
        while (nums[right] > MID)
        {
            --right;
        }
        if (left <= right)
        {
            std::swap(nums[left], nums[right]);
            ++left;
            --right;
        }
        
    } while (left <= right);
    if (LEFT < right)
    {
        qSort(LEFT, right);
    }
    if (left < RIGHT)
    {
        qSort(left, RIGHT);
    }
    return ;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    qSort(0, (n - 1));

    for (int i = 0; i < n; ++i)
    {
        cout << nums[i] << ' ';
    }
    return 0;
}
