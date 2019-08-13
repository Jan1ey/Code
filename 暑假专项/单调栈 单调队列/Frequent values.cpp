#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100005;

int n, q;
int num[maxn], cnt[maxn], lg[maxn];
int st[maxn][30];

int query(int l, int r)
{
    if(l > r) return 0;
    int k = lg[r-l+1];
    //cout<<k<<endl;
    return max(st[l][k], st[r-(1<<k)+1][k]);
}

int main()
{

    while(~scanf("%d", &n) & n){
    scanf("%d", &q);
    for(int i = 1; i <= n; i++) scanf("%d", &num[i]);
    cnt[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(num[i] == num[i-1]) cnt[i] = cnt[i-1]+1;
        else cnt[i] = 1;
    }
    lg[0] = -1;
    for(int i = 1; i <= n; i++)
        st[i][0] = cnt[i], lg[i] = ((i&(i-1))==0) ? lg[i-1]+1 : lg[i-1];
    for(int i = 1; i <= 30; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(j+(1<<(i-1)) <= n)
                st[j][i] = max(st[j][i-1], st[j+(1<<(i-1))][i-1]);
        }
    }
    while(q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int ans1 = 0;
        if(cnt[l] != 1)
            while(num[l] == num[l-1] && l <= r) l++, ans1++;
        int ans2 = query(l, r);
       // cout<<ans1<<endl;
       // cout<<ans2<<endl;
        printf("%d\n", max(ans1, ans2));
    }
    }
    return 0;
}
