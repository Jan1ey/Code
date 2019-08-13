#include <bits/stdc++.h>

using namespace std;

long long a[200005];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
    sort(a+1, a+n+1);
    a[0] = a[n], a[n+1] = a[1];
    int flag = 1;
    if(a[n] >= a[n-1]+a[n+1]) swap(a[n], a[n-1]);
    a[0] = a[n], a[n+1] = a[1];
    for(int i = 1; i <= n; i++)
    {
        if(a[i] >= a[i-1]+a[i+1]) flag = 0;
    }
    if(flag)
    {
        puts("YES");
        for(int i = 1; i <= n; i++) printf("%I64d%c", a[i], " \n"[i==n]);
    }
    else puts("NO\n");
    return 0;
}
