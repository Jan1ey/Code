//
// Created by mile on 2019/7/23.
//
//HDU-3572
//最大流+思维构图

#include <bits/stdc++.h>

#define maxn 2100
#define ps push
#define pb push_back
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;

struct Edge {
    int from, to, flow, cap;
    Edge() {}
    Edge(int a, int b, int c, int d) : from(a), to(b), cap(c), flow(d) {}
};

struct Dinic {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int vis[maxn], cur[maxn], d[maxn];

    void init(int n) {
        for(int i = 0; i <= n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int cap) {
        edges.pb(Edge(from, to, cap, 0));
        edges.pb(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].pb(m-2);
        G[to].pb(m-1);
    }

    bool BFS() {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for(int i = 0; i < G[u].size(); i++) {
                Edge& e = edges[G[u][i]];
                if(!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[u]+1;
                    Q.ps(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x, int a) {
        if(x == t || a == 0) return a;
        int flow = 0, f;
        for(int& i = cur[x]; i < G[x].size(); i++) {
            Edge& e = edges[G[x][i]];
            if(d[x]+1 == d[e.to] && (f = DFS(e.to, min(a, e.cap-e.flow))) > 0) {
                e.flow += f;
                edges[G[x][i]^1].flow -= f;
                flow += f;
                a -= f;
                if(a == 0) break;
            }
        }
        return flow;
    }

    int MaxFlow(int s, int t) {
        this->s = s, this->t = t;
        int flow = 0;
        while(BFS()) {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
}a;

int main()
{
    //freopen("C:\\Users\\mile\\OneDrive\\cpp\\in.txt", "r", stdin);
    int t, Case = 1;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        a.init(maxn-1);
        int mx = 0;
        int sum = 0;
        for (int i = 1; i <= n; i++){
            int p, s, e;
            scanf("%d%d%d", &p, &s, &e);
            mx = max(mx, e);
            a.AddEdge(0, i, p);
            for(int j = s; j <= e; j++) {
                a.AddEdge(i, j+n, 1);
            }
            sum += p;
        }
        for(int i = 1; i <= mx; i++) a.AddEdge(i+n, mx+n+1, m);
        int ans = a.MaxFlow(0, mx+n+1);
        printf("Case %d: ", Case++);
        if(ans == sum) puts("Yes\n");
        else puts("No\n");
    }
    return 0;
}


