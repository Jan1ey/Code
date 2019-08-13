//
// Created by mile on 2019/7/27.
//

#include <bits/stdc++.h>

#define ps push
#define pb push_back
#define mp make_pair
#define maxn 100005
#define INF 0x3f3f3f
using namespace std;

struct Edge {
    int from, to, cap, flow, cost;
};

int M = 50;
vector<Edge> tree;
vector<int> v[maxn];
int numfa[maxn];

void addedges(int from, int to, int cap, int flow, int cost) {
    tree.pb((Edge){from, to, cap, 0, cost});
    int m = tree.size();
    v[from].pb(m-1);
}

struct MCMF {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn];
    int d[maxn];
    int p[maxn];
    int a[maxn];

    void init(int n) {
        this->n = n;
        for(int i = 0; i <= n ;i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int cap, int cost) {
        edges.pb((Edge){from, to, cap, 0, cost});
        edges.pb((Edge){to, from, 0, 0, -cost});
        m = edges.size();
        G[from].pb(m-2);
        G[to].pb(m-1);
    }

    bool SPFA(int s, int t, int &flow, int& cost) {
        this->s = s, this->t = t;
        for(int i = 0; i <= n; i++) d[i] = INF;
        memset(inq, 0, sizeof(inq));
        d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = INF;

        queue<int> Q;
        Q.push(s);
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();
            inq[u] = 0;
            for(int i = 0; i < G[u].size(); i++) {
                Edge& e = edges[G[u][i]];
                if(e.cap > e.flow && d[e.to] > d[u]+ e.cost) {
                    d[e.to] = d[u]+e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap-e.flow);
                    if(!inq[e.to]) { Q.ps(e.to); inq[e.to] = 1; }
                }
            }
        }
        if(d[t] == INF) return false;
        flow += a[t];
        cost += d[t] * a[t];
        int u = t;
        while(u != s) {
            edges[p[u]].flow += a[t];
            edges[p[u]^1].flow -= a[t];
            u = edges[p[u]].from;
        }
        return true;
    }

    int MinCost(int s, int t) {
        this->s = s, this->t = t;
        int flow = 0, cost = 0;
        while(SPFA(s, t, flow, cost));
        return cost;
    }

};

MCMF a;

int dfs(int u) {
    if(v[u].size() == 0) {
        a.AddEdge(0, u, M, 0);
        numfa[u] = 1;
        return numfa[u];
    }
    for(int i = 0; i < v[u].size(); i++) {
        Edge e = tree[v[u][i]];
        numfa[u] += dfs(e.to);
        a.AddEdge(e.to, u, numfa[e.to]*M-e.cost, 0);
    }
    return numfa[u];
}

int main()
{
    int t, Case = 1;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i <= n; i++) v[i].clear(), numfa[i] = 0;
        tree.clear();
        a.init(n);
        for(int i = 1; i < n; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addedges(v, u, 0, 0, w);
        }
        dfs(1);
        int m;
        scanf("%d", &m);
        for(int i = 1; i <= m; i++) {
            int u, v, w, c;
            scanf("%d%d%d%d", &u, &v, &w, &c);
            a.AddEdge(u, v, w, c);
        }
        for(int i = 0; i < a.edges.size(); i++) {
            //cout<<a.edges[i].from<<" "<<a.edges[i].to<<" "<<a.edges[i].cap<<" "<<a.edges[i].cost<<endl;
        }
        int ans = a.MinCost(0,1);
        if(ans != INF) {
            printf("Case #%d: %d\n", Case++, ans);
        } else {
            printf("Case #%d: -1\n", Case++);
        }
    }
    return 0;
}