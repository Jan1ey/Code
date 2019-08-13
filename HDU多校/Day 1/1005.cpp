//
// Created by mile on 2019/7/27.
//
// HDU-6582 最短路+网络流

#include <bits/stdc++.h>

#define ps push
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define maxn 10005

using namespace std;

struct Edge {
    long long from, to, dist, cap, flow;
    Edge(int a, int b, int c) : from(a), to(b), dist(c) {cap = 0, flow = 0;}
    Edge(int a, int b, int c, int d) : from(a), to(b), cap(c), flow(d) {dist = 0;}
};

struct HeadNode {
    long long d, u;
    bool operator < (const HeadNode& rhs) const {
        return d > rhs.d;
    }
};

struct Dijkstra {
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool done[maxn];
    long long d[maxn];
    int p[maxn];

    void init(int n) {
        this->n = n;
        for(int i = 0; i <= n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int dist) {
        edges.pb(Edge(from, to, dist));
        m = edges.size();
        G[from].pb(m-1);
    }

    void dijkstra(int s) {
        priority_queue<HeadNode> Q;
        for(int i = 1; i <= n; i++) d[i] = LONG_LONG_MAX;
        d[s] = 0;
        memset(done, 0, sizeof(done));
        Q.ps((HeadNode){0, s});
        while(!Q.empty()) {
            HeadNode x = Q.top(); Q.pop();
            int u = x.u;
            if(done[u]) continue;
            done[u] = true;
            for(int i = 0; i < G[u].size(); i++) {
                Edge& e = edges[G[u][i]];
                if(d[e.to] > d[u]+e.dist) {
                    d[e.to] = d[u]+e.dist;
                    p[e.to] = G[u][i];
                    Q.ps((HeadNode){d[e.to], e.to});
                }
            }
        }
    }
};

Dijkstra a;

struct Dinic {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int d[maxn], cur[maxn];
    bool vis[maxn];

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
        Q.ps(s);
        d[s] = 0;
        vis[s] = 1;
        while(!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for(int i = 0; i < G[x].size(); i++) {
                Edge& e = edges[G[x][i]];
                if(!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[x]+1;
                    Q.ps(e.to);
                }
            }
        }
        return vis[t];
    }

    long long DFS(int x, long long a) {
        if(x == t || a == 0) return a;
        long long flow = 0, f;
        for(int& i = cur[x]; i < G[x].size(); i++) {
            Edge& e = edges[G[x][i]];
            if(d[x]+1 == d[e.to] && (f=DFS(e.to, min(a, e.cap-e.flow)))> 0) {
                e.flow += f;
                edges[G[x][i]^1].flow -= f;
                flow += f;
                a -= f;
                if(a == 0) break;
            }
        }
        return flow;
    }

    long long MaxFlow(int s, int t) {
        this->s = s; this->t = t;
        long long flow = 0;
        while(BFS()) {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, LONG_LONG_MAX);
        }
        return flow;
    }
};

Dinic b;

vector<Edge> edges;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        a.init(n), b.init(n);
        edges.clear();
        for(int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%lld%lld%lld", &u, &v, &w);
            a.AddEdge(u, v, w);
            edges.pb(Edge(u, v, w));
        }
        a.dijkstra(1);
        if(a.d[n] == LONG_LONG_MAX) {
            puts("0");
            continue;
        }
        for(auto it : edges) {
            //cout<<it.from<<" "<<it.to<<" "<<it.dist<<" "<<a.d[it.from]<<" "<<a.d[it.to]<<endl;
            if(it.dist == a.d[it.to]-a.d[it.from]) {

                b.AddEdge(it.from, it.to, it.dist);
            }
        }
        long long ans = b.MaxFlow(1, n);
        printf("%lld\n", ans);
    }
    return 0;
}
