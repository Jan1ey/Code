//
// Created by mile on 2019/8/3.
//
//HDU-4374
//单调队列+dp

#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
using namespace std;

int dp[105][10005], mat[105][10005], sum[105][10005];
pair<int, int> st[10005];

int main()
{
    int n, m, s, t;
    while(~scanf("%d%d%d%d", &n, &m, &s, &t)) {
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &mat[i][j]);
                sum[i][j] = sum[i][j - 1] + mat[i][j];
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = -INF;
            }
        }
        dp[0][s] = 0;
        for (int i = 1; i <= n; i++) {
            int tail = 1, back = 0;
            for (int j = 1; j <= m; j++) {
                if (tail <= back && j - st[tail].second > t) tail++;
                while (tail <= back && st[back].first <= (dp[i - 1][j] - sum[i][j - 1])) back--;
                st[++back] = make_pair(dp[i - 1][j] - sum[i][j - 1], j);
                dp[i][j] = st[tail].first + sum[i][j];
            }
            tail = 1, back = 0;
            for (int j = m; j >= 1; --j) {
                if (tail <= back && st[tail].second - j > t) tail++;
                while (tail <= back && st[back].first <= (dp[i - 1][j] + sum[i][j])) --back;
                st[++back] = make_pair(dp[i - 1][j] + sum[i][j], j);
                dp[i][j] = max(dp[i][j], st[tail].first - sum[i][j - 1]);
            }
        }
        int ans = -INF;
        for (int i = 1; i <= m; i++) ans = max(ans, dp[n][i]);
        printf("%d\n", ans);
    }
    return 0;
}