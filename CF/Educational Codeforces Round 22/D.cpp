#include <bits/stdc++.h>

using namespace std;

const int maxn = 5005;
const int maxm = 100005;

int a[maxn], pre[maxm], mod[maxm], dp[maxn][maxn];

int main()
{
    int n;
    int ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 0; i <= n; i++)
    {
        memset(pre, 0, sizeof(pre));
        memset(mod, 0, sizeof(mod));
        for(int j = 1; j < i; j++)
        {
            pre[a[j]] = max(pre[a[j]], dp[i][j]);
            mod[a[j]%7] = max(mod[a[j]%7], dp[i][j]);
        }
        for(int j = 1+i; j <= n; j++)
        {
            dp[i][j] = max(max(pre[a[j]-1], pre[a[j]+1]), max(dp[i][0], mod[a[j]%7]))+1;
            pre[a[j]] = max(pre[a[j]], dp[i][j]);
            mod[a[j]%7] = max(mod[a[j]%7], dp[i][j]);
            dp[j][i] = dp[i][j];
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
