//
// Created by mile on 2019/7/20.
//
/*
#include <bits/stdc++.h>

using namespace std;
char s[1005];
int pre[1005], mat[1005][1005];
int vis[1005], sz[1005];
pair<int, int> h[1005];
int ans1, ans2;

int find_pre(int x)
{
    if(pre[x] == x) return x;
    else return pre[x] = find_pre(pre[x]);
}

void _union(int a, int b)
{
    a = find_pre(a), b = find_pre(b);
    pre[a] = b;
    sz[b] += sz[a];
    return ;
}

void solve(int x)
{
    if(x > ans1) ans2 = ans1, ans1 = x;
    else if(x > ans2) ans2 = x;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    ans1 = ans2 = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%s", s+1);
        for(int j = 1; j <= m; j++) mat[i][j] = (s[j] == '0' ? 0 : 1);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
             mat[i][j] = (mat[i][j] == 0 ? 0 : mat[i-1][j]+mat[i][j]);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) vis[j] = 0, pre[j] = j, sz[j] = 1, h[j] = make_pair(mat[i][j], j);
        sort(h+1, h+m+1);
        for(int j = m; j >= 1; j--) {
            int x = h[j].second; vis[x] = 1;
            if(vis[x-1]) _union(x-1, x);
            if(vis[x+1]) _union(x, x+1);
            int len = find_pre(x);
            len = sz[len];
            //cout<<len<<" "<<h[j].first<<endl;
            solve(len*h[j].first);
            solve(len*(h[j].first-1));
            solve((len-1)*h[j].first);
        }
    }
    cout<<ans2<<endl;
    return 0;
}
*/