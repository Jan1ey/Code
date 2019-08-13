#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 2005;

int w, t, maxp;
int ap[maxn], bp[maxn], as[maxn], bs[maxn];
int dp[maxn][maxn];
pair<int, int> de[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &t, &maxp, &w);
        for(int i = 1; i <= t; i++)
        {
            scanf("%d%d%d%d", &ap[i], &bp[i], &as[i], &bs[i]);
        }
        for(int i = 0; i <= t; i++)
        {
            for(int j = 0; j <= maxp; j++)
                dp[i][j] = -INT_MAX;
        }
        for(int i = 1; i <= w+1; i++)
        {
            for(int j = 0; j <= min(maxp, as[i]); j++)
                dp[i][j] = -j*ap[i];
        }
        dp[0][0] = 0;
        for(int i = 1; i <= t; i++)
        {
            for(int j = 0; j <= maxp; j++)
                dp[i][j] = max(dp[i-1][j], dp[i][j]);
            if(i <= w+1) continue;
            int pre = i-w-1;
            int hd = 1, bk = 0;
            for(int j = 0; j <= maxp; j++)
            {
                int val = dp[pre][j]+j*ap[i];
                while(bk >= hd && de[bk].first <= val) bk--;
                de[++bk].first = val; de[bk].second  = j;
                while(bk >= hd && de[hd].second+as[i] < j) hd++;
                dp[i][j] = max(dp[i][j], de[hd].first-j*ap[i]);
            }
            hd = 1, bk = 0;
            for(int j = maxp; j >= 0; j--)
            {
                int val = dp[pre][j]+j*bp[i];
                while(bk >= hd && de[bk].first <= val) bk--;
                de[++bk].first = val, de[bk].second = j;
                while(bk >= hd && de[hd].second-bs[i] > j) hd++;
                dp[i][j] = max(dp[i][j], de[hd].first-j*bp[i]);
            }
        }
        int ans = 0;
        for(int i = 0; i <= maxp; i++)
            ans = max(ans, dp[t][i]);
        printf("%d\n", ans, 0);
    }
    return 0;
}
