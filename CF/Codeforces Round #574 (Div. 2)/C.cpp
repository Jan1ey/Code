//
// Created by mile on 2019/7/18.
//

#include <bits/stdc++.h>

using namespace std;
const int maxn = 100005;

long long a[maxn], b[maxn];
long long dp[2][maxn];

int main()
{
    int n;
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++) scanf("%lld", &b[i]);
    dp[0][0] = 0, dp[1][0] = 0;
    dp[1][1] = b[1], dp[0][1] = a[1];
    long long ans = max(a[1], b[1]);
    for(int i = 2; i <= n; i++) {
        dp[0][i] = max(dp[1][i - 1] + a[i], dp[1][i - 2] + a[i]);
        dp[1][i] = max(dp[0][i - 1] + b[i], dp[0][i - 2] + b[i]);
        ans = max(max(dp[0][i], dp[1][i]), ans);
    }
    cout<<ans<<endl;
}