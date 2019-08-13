//
// Created by mile on 2019/7/23.
//

#include <bits/stdc++.h>

#define ps push
#define pb push_back
#define maxv 100005
#define maxe 500005
using namespace std;

struct Cycle {
    int n, s;
    vector<int> G[maxv];
    int color[maxv], fa[maxv];

    Cycle() {}
    Cycle(int a, int c) : n(a), s(c) {}

    void init(int n, int s) {
        this->n = n, this->s = s;
        for(int i= 1; i <= n; i++) G[i].clear(), color[i] = 0, fa[i] = i;
    }

    void AddEdge(int u, int v) {
        G[u].pb(v);
        G[v].pb(u);
    }

    bool BFS() {
        //memset(vis, 0, sizeof(vis));
        //memset(color, 0, sizeof(color));
        queue<int> Q;
        Q.ps(s);
        color[s] = 2;
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for(int i = 0; i < G[u].size(); i++) {
                int v = G[u][i];
                if(color[v]) {
                    if(color[v] == color[u]) return 1;
                } else {
                    color[v] = (color[u] == 2 ? 1 : 2);
                    Q.ps(v);
                }
            }
        }
        return 0;
    }

    int seek(int a) {
        if(fa[a] == a) return a;
        else return fa[a] = seek(fa[a]);
    }

    void merge(int a, int b) {
        a = seek(a), b = seek(b);
        if(a != b) fa[b] = a;
    }

    bool solve() {
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(fa[i] == i) cnt++;
            if(cnt > 1) return 0;
        }
        if(BFS()) {
           return 1;
        } else {
            return 0;
        }
    }
}a;

int main()
{
    //freopen("C:\\Users\\mile\\OneDrive\\cpp\\in.txt", "r", stdin);
    int n, m, s, t, Case = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &n, &m, &s);
        a.init(n, s+1);
        for(int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            ++u, ++v;
            a.AddEdge(u, v);
            u = a.seek(u), v = a.seek(v);
            if(u != v) a.merge(u, v);
        }
        //cout<<1<<endl;
        if(a.solve()) {
            printf("Case ");
            printf("%d: ", Case++);
            puts("YES");
        } else {
            printf("Case ");
            printf("%d: ", Case++);
            puts("NO");
        }
    }
    return 0;
}