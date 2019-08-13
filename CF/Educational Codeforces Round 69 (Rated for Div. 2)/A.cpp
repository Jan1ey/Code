//
// Created by mile on 2019/8/5.
//
#include <bits/stdc++.h>

using namespace std;

char ans[1005][1005];
int num[1005][5], score[1005];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%s", ans[i]+1);
        for(int j = 1; j <= m; j++) num[j][ans[i][j]-'A']++;
    }
    for(int i = 1; i <= m; i++) scanf("%d", &score[i]);
    int mx = 0;
    for(int i = 1; i <= m; i++) {
        int tmp = 0, sc = 0;
        for(int j = 0; j <= 4; j++) {
            if(num[i][j] > tmp) {
                tmp = num[i][j];
                sc = tmp*score[i];
            }
        }
        mx += sc;
    }
    printf("%d\n", mx);
    return 0;
}
