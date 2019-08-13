#include <bits/stdc++.h>

using namespace std;

int d[100005];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        d[u]++, d[v]++;
    }
    int flag = 1;
    for(int i = 1; i <= n; i++)
    {
        if(d[i] == 2) flag = 0;
    }
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}
