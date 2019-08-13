//
// Created by mile on 2019/7/20.
//
/*
#include <bits/stdc++.h>

using namespace std;

int n;
int vis[35];
long long ans = 0;
int maps[35][35], delta[35][2], cnt[2];

void dfs(int x, long long tmp)
{
    if(x > 2*n){
        ans = max(ans,  tmp);
        return ;
    }
    for(int i = 0; i < 2; i++) {
        if (cnt[i] < n) {
            cnt[i]++;
            for(int j = x+1; j <= n*2; j++) delta[j][i^1] += maps[x][j];
            dfs(x+1, tmp+delta[x][i]);
            for(int j = x+1; j <= n*2; j++) delta[j][i^1] -= maps[x][j];
            cnt[i]--;
        }
    }
}


int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n*2; i++)
        for(int j = 1; j <= n*2; j++)
            scanf("%d", &maps[i][j]);
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}
*/