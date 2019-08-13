//
// Created by mile on 2019/7/29.
//
//Dijkstra模板

#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
using namespace std;

const int maxn = 100005;

struct Edge {          //弧
    int from, to, dist;//起点，终点，距离
};

struct HeadNode {      //优先队列节点
    int d, u;
    bool operator < (const HeadNode& rhs) const {
        return d > rhs.d;
    }
};

struct Dijkstra {
    int n, m;            //点数和边数
    vector<Edge> edges;  //边列表
    vector<int> G[maxn]; //每个节点出发的边编号
    bool done[maxn];     //是否已永久编号
    int d[maxn];         //s到各个点的距离
    int p[maxn];         //最短路中的上一条边

    void init(int n) {
        this->n = n;
        for(int i = 0; i <= n; i++) G[i].clear(); //清空邻接表
        edges.clear();  //清空边表
    }

    void AddEdge(int from, int to, int dist) {
        //如果无向图，每条边调用两次AddEdge
        edges.push_back((Edge){from, to, dist});
        m = edges.size();
        G[from].push_back(m-1);
    }

    void dijkstra(int s) {  //求s到所有点的距离
        priority_queue<HeadNode> Q;
        for(int i = 0; i <= n; i++) d[i] = INF;
        d[s] = 0;
        memset(done, 0, sizeof(done));
        Q.push((HeadNode){0, s});
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
                    Q.push((HeadNode){d[e.to], e.to});
                }
            }
        }
    }
};

Dijkstra a;

int main()
{
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    a.init(n);
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        a.AddEdge(u, v, w);
    }
    a.dijkstra(s);
    for(int i = 1; i < n; i++) {
        printf("%d ", a.d[i]);
    }
    printf("%d\n", a.d[n]);
    return 0;
}