#include <bits/stdc++.h>

using namespace std;

int a[100005];

int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    int stp = 0, same = 0;
    a[0] = -1;
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++)
    {
        stp += a[i] - (i-1);
        if(a[i] == a[i-1])
        {
            same++;
            if(same == 2)
            {
                puts("cslnb");
                return 0;
            }
            else if(a[i] == 0 || (i>2 && a[i-2] == a[i]-1))
            {
                puts("cslnb");
                return 0;
            }
        }
    }
    if(stp%2 == 0) puts("cslnb");
    else puts("sjfnb");
    return 0;
}
