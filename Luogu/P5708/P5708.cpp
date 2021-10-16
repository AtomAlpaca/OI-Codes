#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a,b,c,q,ans;
    cin >> a >> b >> c;
    q = (a + b + c) / 2;
    ans = sqrt(q * (q - a) * (q - b) * (q - c));
    printf("%.1lf",ans);
    return 0;
}