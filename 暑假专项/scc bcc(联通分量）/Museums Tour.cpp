//
// Created by mile on 2019/7/30.
//
//拆点+强联通缩点+递归dp求DAG上最长路
//CodeForces-1137C

#include <bits/stdc++.h>

using namespace std;
const int maxn = 5000050;

int dfs_clock, scc_cnt;
int dfn[maxn], low[maxn], sccno[maxn];
int num[maxn], c[maxn];
int head[maxn], edge[maxn], nxt[maxn], cnt;
bool vis[maxn];
vector<int> F[maxn];
int st[maxn], top;
char s[maxn/40][55];

void dfs(int u) {
    dfn[u] = low[u] = ++dfs_clock;
    st[++top] = u;
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = edge[i];
        if(!dfn[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if(!sccno[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]) {
        ++scc_cnt;
        while(true) {
            int x = st[top--];
            sccno[x] = scc_cnt;
            if(x == u) break;
        }
    }
}
void find_bcc(int n) {
    dfs_clock = scc_cnt = top = 0;
    for(int i = 0; i < n; i++) {
        if(!dfn[i]) dfs(i);
    }
}

int cal(int s) {
    if(c[s] != -1) return c[s];
    int tmp = 0;
    for(auto &i : F[s]) {
        tmp = max(tmp, cal(i));
    }
    return c[s] = tmp+num[s];
}

void addedge(int u, int v){
    edge[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

int main()
{
    int n, m, d;
    memset(c, -1, sizeof(c));
    memset(head, -1, sizeof(head));
    cnt = 0;
    scanf("%d%d%d", &n, &m, &d);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        for(int j = 0; j < d; j++) {
            addedge(u*d+j, v*d+(j+1)%d);
        }
    }
    for(int i = 0; i < n; i++) scanf("%s", s[i]);
    find_bcc(n*d);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < d; j++) {
            if(s[i][j] == '1' && !vis[sccno[i*d+j]]) {
                num[sccno[i*d+j]]++;
                vis[sccno[i*d+j]] = true;
            }
        }
        for(int j = 0; j < d; j++) {
            vis[sccno[i*d+j]] = false;
        }
    }
    for(int i = 0; i < n*d; i++) {
        for(int j = head[i]; ~j; j = nxt[j]) {
            if(j >= maxn || j < 0) break;
            int x = edge[j];
            if(sccno[i] != sccno[x]) {
                F[sccno[i]].push_back(sccno[x]);
            }
        }
    }
    printf("%d\n", cal(sccno[0]));
    return 0;
}
