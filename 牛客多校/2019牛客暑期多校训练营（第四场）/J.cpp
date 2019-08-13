//
// Created by mile on 2019/7/27.
//

#include <bits/stdc++.h>

#define ps push
#define pb push_back
#define mp make_pair
#define maxn 505
#define INF 0x3f3f3f3f
using namespace std;

struct HeadNode {
    int d, u;
    bool operator < (const HeadNode& rhs) const {
        return d > rhs.d;
    }
};

struct Dijkstra {
    int n, m;
    int edges[maxn][maxn];
    vector<int> G[maxn];
    bool done[maxn];
    int d[maxn];
    int p[maxn];
    int vis[maxn];
    int deep[maxn];

    void init(int n) {
        this->n = n;
        for(int i = 0; i <= n; i++) {
            for(int j = 0;j <= n; j++) edges[i][j] = INF;
        }
    }

    void AddEdges(int from, int to, int dist) {
        edges[to][from] = edges[from][to] = min(edges[from][to], dist);
        G[from].push_back(to);
        G[to].push_back(from);
    }

    void dijkstra(int s) {
        memset(p, 0, sizeof(p));
        priority_queue<HeadNode> Q;
        for(int i = 0;i <= n; i++) d[i] = INF;
        d[s] = 0;
        memset(done, 0, sizeof(done));
        Q.ps((HeadNode){0, s});
        while(!Q.empty()) {
            HeadNode x = Q.top(); Q.pop();
            int u = x.u;
            if(done[u]) continue;
            done[u] = true;
            for(int i = 0; i < G[u].size(); i++) {
                int e =  G[u][i];
                if(d[e] > d[u]+edges[u][e]) {
                    d[e] = d[u]+edges[u][e];
                    p[e] = u;
                    Q.push((HeadNode){d[e], e});
                }
            }
        }
    }
}a;


int main()
{
    int n, m, s, t, k;
    scanf("%d%d%d%d%d", &n, &m, &s, &t, &k);
    a.init(n);
    a.n = n;
    int selfloop = INF;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if(u == v && u == s && s == t) {
            selfloop = w;
            continue;
        }
        else if(u == v) continue;
        a.AddEdges(u, v, w);
    }
    int o;
    a.dijkstra(s);
    if(a.d[t] > selfloop || a.d[t] == 0) o = selfloop;
    else o = a.d[t];
    if(k >= 1 && o == selfloop) {
        puts("0");
        return 0;
    }
    vector<int> ans;
    for(int i = t; ; i = a.p[i])
    {
        if(a.p[i] == 0) break;
        ans.pb(a.edges[i][a.p[i]]);
        if(a.p[i] == s) break;
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(a.edges[i][j] != INF) a.edges[i][j] = 1;
        }
    }
    a.dijkstra(s);
    if(a.d[t] <= k) {
        puts("0");
        return 0;
    }
    sort(ans.begin(), ans.end());
    int l = 0;
    for(int i = 0; i <= ans.size()-k-1; i++) l+= ans[i];
    cout<<l<<endl;
    return 0;
}