#include <bits/stdc++.h>
using namespace std;


int main()
{
    unsigned long long ans,n;
    cin >> n;
    ans = n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4;
    printf("%lld",ans);
    
    return 0;
}