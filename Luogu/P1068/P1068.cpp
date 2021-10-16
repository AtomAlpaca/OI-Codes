#include <iostream>
#include <cmath>
#include <algorithm>

using std::cout;
using std::cin;

struct Student
{
    int score;
    int id;
};


int main(int argc, char const *argv[])
{
    int * n = new int;
    int * m = new int;

    cin >> *n >> *m;
    Student stu[*n];
    
    for (int i = 0; i < *n; ++i)
    {
        cin >> stu[i].id >> stu[i].score;
    }

    std::sort(stu, stu + *n, [=](Student stu1, Student stu2){
        if (stu1.score > stu2.score)
        {
            return true;
        }
        else if (stu1.score == stu2.score)
        {
            return stu1.id < stu2.id;
        }
        else
        {
            return false;
        }
    });

    *m = std::floor(1.0 * (*m) * 1.5) - 1;
    int last = stu[*m].score;

    while (stu[*m].score == last)
    {
        ++(*m);
    }
    if (*m == *n)
    {
        --(*m);
    }
    cout << stu[*m - 1].score << " " << *m << "\n";
    for (int i = 0; i < *m; i++)
    {
        cout << stu[i].id << " " << stu[i].score << "\n";
    }
    
    delete m;
    delete n;
    return 0;
}
