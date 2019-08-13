//
// Created by mile on 2019/8/3.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1005;
ll num[maxn][maxn], suf[maxn][maxn], d[maxn];

int main()
{
    int t, cnt = 0;
    scanf("%d", &t);
    while(t--) {
        cnt++;
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                scanf("%lld", &num[i][j]);
                num[i][j] = -num[i][j];
            }
        }
        memset(suf, 0, sizeof(suf));
        for(int i = 1; i <= m; i++) scanf("%lld", &d[i]);
        for(int i = 1; i <= n; i++) {
            for(int j = m-1; j >= 0; j--) {
                suf[i][j] = max(0ll, suf[i][j+1]+num[i][j+1]);
            }
        }
        ll sum = 0, ans = 0;
        for(int j = 0; j <= m; j++) {
            for(int i = 1; i <= n; i++) sum += num[i][j];
            sum += d[j];
            ll tmp = 0, mn = 1e18;
            for(int i = 1; i <= n; i++) tmp += suf[i][j], mn = min(mn, suf[i][j]);
            ans = max(ans, sum-mn+tmp);
        }
        printf("Case #%d: %lld\n", cnt, ans);
    }
    return 0;
}