#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 16005*2;
const int maxk = 105*10;

int n, k;
int dp[maxk][maxn];
pair<int, int> de[maxn];
struct worker
{
    int l, p, s;
    bool operator < (const worker& a)const
    {
        return s < a.s;
    }
}wk[maxk];

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= k; i++)
        scanf("%d%d%d", &wk[i].l, &wk[i].p, &wk[i].s);
    sort(wk+1, wk+k+1);
    for(int i = 1; i <= k; i++)
    {
        int hd = 1, bk = 0, pre = i-1;
        for(int j = max(0, wk[i].s-wk[i].l); j <= wk[i].s-1; j++)
        {
            //if(j < wk[i].s || j >= wk[i].s+wk[i].l) continue;
            int val = dp[i-1][j]-wk[i].p*j;
            while(hd <= bk && de[bk].first <= val) bk--;
            de[++bk].first = val, de[bk].second = j;
        }
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(j >= wk[i].s)
            {
                while(hd <= bk && de[hd].second < j-wk[i].l) hd++;
                if(hd <= bk) dp[i][j] = max(dp[i][j], de[hd].first+j*wk[i].p);
            }
        }
    }
   /* for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    puts("");*/
    printf("%d\n", dp[k][n]);
    return 0;
}
