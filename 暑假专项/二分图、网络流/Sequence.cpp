//
// Created by mile on 2019/7/24.
//
//
//dp + 网络流最大流

#include <bits/stdc++.h>


#define pb push_back
#define ps push
#define mp make_pair
using namespace std;
const int maxn = 100005;

int dp[maxn], num[maxn];

struct Edge {
    int from, to, cap, flow;
    Edge() {}
    Edge(int a, int b, int c, int d) : from(a), to(b), cap(c), flow(d) {}
};

struct Dinic {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int vis[maxn], d[maxn], cur[maxn];

    void AddEdge(int from, int to, int cap, int flow) {
        edges.pb(Edge(from, to, cap, 0));
        edges.pb(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].pb(m-2);
        G[to].pb(m-1);
    }

    void init(int n) {
        for(int i = 0; i <= 2*n+1; i++) G[i].clear();
        edges.clear();
    }

    bool BFS() {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while(!Q.empty()) {
            int x = Q.front(); Q.pop();
            for(int i = 0; i < G[x].size(); i++) {
                Edge& e = edges[G[x][i]];
                if(!vis[e.to] && e.cap > e.flow) {
                    d[e.to] = d[x]+1;
                    vis[e.to] = 1;
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
            if(d[x]+1 == d[e.to] && (f = (DFS(e.to, min(a, e.cap-e.flow))))>0) {
                e.cap -= f;
                e.flow += f;
                edges[G[x][i]^1].flow -=f;
                flow += f;
                a -= f;
            }
        }
        return flow;
    }

    int MaxFlow(int s, int t) {
        this->s = s, this->t = t;
        int ans = 0;
        while(BFS()) {
            memset(cur, 0, sizeof(cur));
            ans += DFS(s, INT_MAX);
        }
        return ans;
    }
};
Dinic a;

int main()
{
    //freopen("C:\\Users\\mile\\OneDrive\\cpp\\in.txt", "r", stdin);
    int n;
    while(~scanf("%d", &n)) {
        int maxlen = 1;
        a.init(n);
        for(int i = 1; i <= n; i++) scanf("%d", &num[i]);
        for(int i = 1; i <= n; i++) {
            dp[i] = 1;
            for(int j = 1; j < i; j++) {
                if(num[j] < num[i]) dp[i] = max(dp[i], dp[j]+1);
                maxlen = max(dp[i], maxlen);
            }
        }
        for(int i = 1; i <= n; i++) {
            a.AddEdge(i, i+n, 1, 0);
            for(int j = i+1; j <= n; j++) {
                if(dp[i]+1 == dp[j]) a.AddEdge(i+n, j, 1, 0);
            }
        }
        for(int i = 1; i <= n; i++) {
            if(dp[i] == 1) a.AddEdge(0, i, 1, 0);
            if(dp[i] == maxlen) a.AddEdge(i, 2*n+1, 1, 0);
        }
        int ans = a.MaxFlow(0, 2*n+1);
        printf("%d\n%d\n", maxlen, ans);
    }
    return 0;
}