//
// Created by mile on 2019/8/4.
//
//区间dp
//dp[i][j] = min(dp[i][j], a[i]*a[j]*a[k]+solve(i, k)+solve(k+1,j));

#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 105;

int a[105], dp[105][105];

int solve(int l, int r) {
    if(dp[l][r] != INF) return dp[l][r];
    if(l+1 == r) return dp[l][r] = 0;
    for(int i = l+1; i < r; i++) {
        dp[l][r] = min(dp[l][r], a[l]*a[r]*a[i]+solve(l, i)+solve(i, r));
    }
    return dp[l][r];
}

int main()
{
    int n;
    while(~scanf("%d", &n)) {
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = INF;
        printf("%d\n", solve(1, n));
    }
    return 0;
}