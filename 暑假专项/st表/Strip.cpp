#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 100005;

int n, s, l;
int num[maxn], dp[maxn];
int mx_st[maxn][30], mn_st[maxn][30];
pair<int, int> de[maxn];

int query(int l, int r)
{
    int k = (int)(log(r-l+1.0)/log(2.0));
    return max(mx_st[l][k], mx_st[r-(1<<k)+1][k])-min(mn_st[l][k], mn_st[r-(1<<k)+1][k]);
}

int main()
{
    scanf("%d%d%d", &n, &s, &l);
    for(int i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    for(int i = 1; i <= n; i++)
        mx_st[i][0] = mn_st[i][0] = num[i];
    for(int j = 1; j < 20; j++) {
        for(int i = 1; i <= n; i++) {
            if(i+(1<<(j-1)) <= n) {
                mx_st[i][j] = max(mx_st[i][j-1], mx_st[i+(1<<(j-1))][j-1]);
                mn_st[i][j] = min(mn_st[i][j-1], mn_st[i+(1<<(j-1))][j-1]);
            }
        }
    }
    if(l > n || query(1, l) > s) {
        puts("-1");
        return 0;
    }
    memset(dp, 0x3f, sizeof(dp));
    de[0] = make_pair(0, 0);
    dp[l] = 1;
    int hd = 0, bk = 1;
    for(int i = l+1; i <= n; i++)
    {
        int le = 1, r = i-l+1, ans = -1;
        while(le <= r) {
            int mid = (le+r)>>1;
            if(query(mid, i) <= s)  r = mid-1, ans = mid;
            else le = mid+1;
        }
        while(hd < bk && de[bk-1].first >= dp[i-l]) bk--;
            de[bk++] = make_pair(dp[i-l], i-l);
        if(ans != -1)
        {
            while(hd < bk && de[hd].second < ans-1) hd++;
            if(hd < bk) dp[i] = min(dp[i], de[hd].first+1);
        }
    }
    if(dp[n] != INF) printf("%d\n", dp[n]);
    else printf("-1\n");
    return 0;
}
