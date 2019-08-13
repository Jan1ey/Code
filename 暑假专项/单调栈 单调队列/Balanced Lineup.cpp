#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define mb make_pair
#define pb push_back
#define ph push
using namespace std;
const int maxn = 80005;

int n, q;
int num[maxn];
int lg[maxn];
int mx_st[maxn][50], mn_st[maxn][50];

int query(int l, int r)
{
    int k = lg[r-l+1];
    return max(mx_st[l][k], mx_st[r-(1<<k)+1][k]) - min(mn_st[l][k], mn_st[r-(1<<k)+1][k]);
}

int main()
{
    lg[0] = -1;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++) lg[i] = ((i&(i-1)) == 0) ? lg[i-1]+1 : lg[i-1];
    for(int i = 1; i <= n; i++) scanf("%d", &num[i]);
    for(int i = 1; i <= n; i++) mx_st[i][0] = mn_st[i][0] = num[i];
    for(int i = 1; (1<<i) <= n; i++)
    {
        for(int j = 1; j+i-1 <= n; j++)
        {
            mx_st[j][i] = max(mx_st[j][i-1], mx_st[j+(1<<(i-1))][i-1]);
            mn_st[j][i] = min(mn_st[j][i-1], mn_st[j+(1<<(i-1))][i-1]);
        }
    }
    while(q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int ans = query(l, r);
        printf("%d\n", ans);
    }
    return 0;
}
