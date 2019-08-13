//
// Created by mile on 2019/7/23.
//
//HDU-1532
//网络流最大流板子题

#include <bits/stdc++.h>

#define maxn 205
#define INF 0x3f3f3f3f
#define LL long long
#define pb push_back
#define ps push
using namespace std;

struct Edge {
    long long from, to, cap, flow;
    Edge() {}
    Edge(int a, int b, int c, int d) : from(a), to(b), cap(c), flow(d) {}
};

struct Dinic {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int vis[maxn], cur[maxn], d[maxn];

    void init(int n, int m, int s, int t) {
        this->n = n, this->m = m, this->s = s, this->t = t;
        for(int i = 1; i <= n; i++) G[i].clear();
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
        vis[s] = 1;
        d[s] = 0;
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

    LL DFS(int x, LL a) {
        if(x == t || a == 0) return a;
        LL flow = 0, f;
        for(int& i = cur[x]; i < G[x].size(); i++) {
            Edge& e = edges[G[x][i]];
            if(d[e.to] == d[x]+1 && (f = DFS(e.to, min(a, e.cap-e.flow))) > 0) {
                e.flow += f;
                edges[G[x][i]^1].flow -= f;
                flow += f;
                a -= f;
                //cout<<f<<endl;
                if(a == 0) break;
            }
        }
        return flow;
    }

    LL MaxFlow(int s, int t) {
        this->s = s, this->t = t;
        LL flow = 0;
        while(BFS()) {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
           // cout<<flow<<endl;
        }
        return flow;
    }
}a;

int main()
{
    //freopen("C:\\Users\\mile\\OneDrive\\cpp\\in.txt", "r", stdin);
    int n, m;
    while(~scanf("%d%d", &m, &n))
    {
        a.init(n, m, 1, n);
        for(int i = 1; i <= m; i++) {
            int u, v, val;
            scanf("%d%d%d", &u, &v, &val);
            a.AddEdge(u, v, val);
        }
        //cout<<"here"<<endl;
        LL ans = a.MaxFlow(1, n);
        printf("%lld\n", ans);
    }
    return 0;
}