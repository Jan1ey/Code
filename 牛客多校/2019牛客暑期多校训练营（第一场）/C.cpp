//
// Created by mile on 2019/7/18.
//

#include <bits/stdc++.h>

using namespace std;
const int maxn = 100005;

int a[maxn], b[maxn];

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        int min1, min2;
        min1 = a[1], min2 = b[1];
        bool flag = true;
        int ans = 1;
        for(int i = 1; i <= n; i++)
        {
            int mn1, mn2;
            mn1 = a[i], mn2 = b[i];
            for(int j = i-1; j >= 1; j--)
            {
                if(mn1 > a[j] && mn2 > b[j])
                {
                    mn1 = a[j] , mn2 = b[j];
                }
                else if(mn1 > a[j] || mn2 > b[j])
                {
                    flag = false;
                }
            }
            if(!flag) break;
            else ans = i;
        }
        printf("%d\n", ans);
    }
    return 0;
}