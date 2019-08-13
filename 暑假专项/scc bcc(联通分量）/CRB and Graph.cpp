//
// Created by mile on 2019/7/30.
//
//HDU-5409
//强连通分量缩点+维护每个分量的最大值

#include <bits/stdc++.h>

using namespace std;
const int maxn = 100001;

int clk, cnt, n, m;
int pre[maxn], low[maxn], isbridge[maxn], vis[maxn], maxnum[maxn], id[maxn];
int idmax[maxn], ans[maxn], U[maxn], V[maxn];
vector<pair<int, int> > G[maxn];

void init() {
    memset(isbridge, 0, sizeof(isbridge));
    memset(pre, 0, sizeof(pre));
    memset(low, 0, sizeof(low));
    clk = 0;
    for(int i = 0; i < maxn; i++) G[i].clear();
}

void dfs(int u, int fa) {
    low[u] = pre[u] = ++clk;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i].first;
        int idx = G[u][i].second;
        if(!pre[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > pre[u]) {
                isbridge[idx] = 1;
            }
        } else if(pre[v] < pre[u] && v != fa) {
            low[u] = min(low[u], pre[v]);
        }
    }
}

void dfs2(int u, int fa) {
    vis[u] = 1;
    maxnum[u] = u;
    id[u] = cnt;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i].first, idx = G[u][i].second;
        if(!isbridge[idx] && v != fa && !vis[v]) {
            dfs2(v, u);
            maxnum[u] = max(maxnum[u], maxnum[v]);
        }
    }
}

void Bcc_Bridge() {
    dfs(1, -1);
    memset(vis, 0, sizeof(vis));
    cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            ++cnt;
            dfs2(i, -1);
        }
    }
    for(int i = 1; i <= n; i++) G[i].clear();
    for(int i = 1; i <= m; i++) {
        int x = U[i], y = V[i];
        if(isbridge[i]) {
            int u = id[x], v = id[y];
            G[u].push_back(make_pair(v, i));
            G[v].push_back(make_pair(u, i));
        }
    }
}

void solve(int u, int fa) {
    pre[u] = ++clk;
    ans[u] = idmax[u];
    for(int i = 0; i < G[u].size(); i++) {
        int x = G[u][i].first;
        if(x != fa) {
            solve(x, u);
            ans[u] = max(ans[u], ans[x]);
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        init();
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            U[i] = u, V[i] = v;
            G[u].push_back(make_pair(v, i));
            G[v].push_back(make_pair(u, i));
        }
        Bcc_Bridge();
        for(int i = 1; i <= n; i++) {
            idmax[id[i]] = maxnum[i];
        }
        int u = 1;
        for(; u <= n; u++) {
            if(idmax[u] == n) break;
        }
        memset(pre, 0, sizeof(pre));
        clk = 0;
        solve(u, 0);
        for(int i = 1; i <= m; i++) {
            int u = U[i], v = V[i];
            if(id[u] == id[v]) {
                printf("0 0\n");
            } else {
                if(pre[id[u]] < pre[id[v]]) {
                    swap(u, v);
                }
                printf("%d %d\n", ans[id[u]], ans[id[u]]+1);
            }
        }
    }
    return 0;
}