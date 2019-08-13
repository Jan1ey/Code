#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 255;

int n, b, k;
int lg[maxn];
int num[maxn][maxn];
int st[maxn][maxn][25], mst[maxn][maxn][25];

int query(int l, int r)
{
    int m = lg[b];
    int mx = max(st[l][r][m], max(st[l+b-(1<<m)][r][m], max(st[l+b-(1<<m)][r+b-(1<<m)][m],st[l][r+b-(1<<m)][m])));
    int mn = min(mst[l][r][m], min(mst[l+b-(1<<m)][r][m], min(mst[l+b-(1<<m)][r+b-(1<<m)][m],mst[l][r+b-(1<<m)][m])));
    //cout<<mst[l][r][m]<<" "<<mst[l+b-(1<<m)][r][m]<<" "<<mst[l+b-(1<<m)][r+b-(1<<m)][m]<<" "<<mst[l][r+b-(1<<m)][m]<<endl;
    return mx-mn;
}

int main()
{
    scanf("%d%d%d", &n, &b, &k);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &num[i][j]), st[i][j][0] = mst[i][j][0] = num[i][j];
    lg[0] = -1;
    for(int i = 1; i <= n; i++)
        lg[i] = ((i&(i-1))==0) ? lg[i-1]+1 : lg[i-1];
    for(int k = 1; k <= 20; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(i+(1<<(k-1)) <= n && j+(1<<(k-1)) <= n)
                {
                    st[i][j][k] = max( max(st[i][j][k-1], st[i+(1<<(k-1))][j+(1<<(k-1))][k-1]), max(st[i][j+(1<<(k-1))][k-1], st[i+(1<<(k-1))][j][k-1]));
                    mst[i][j][k] = min( min(mst[i][j][k-1], mst[i+(1<<(k-1))][j+(1<<(k-1))][k-1]), min(mst[i][j+(1<<(k-1))][k-1], mst[i+(1<<(k-1))][j][k-1]));
                }
    while(k--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int ans = query(l, r);
        printf("%d\n", ans);
    }
    return 0;
}
