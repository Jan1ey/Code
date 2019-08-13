//
// Created by mile on 2019/8/4.
//
//HDU-4123
//树形dp+RMQ

#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define debug cout<<"here"<<endl
using namespace std;
const int maxn = 50005;

struct Edge {
    int to, from, next, w;
};
Edge edges[maxn*2];
int head[maxn], cnt = 0;
int mx[maxn], smx[maxn], mxson[maxn], smxson[maxn];

void addedge(int u, int v, int w) {
    edges[cnt].from = u;
    edges[cnt].to = v;
    edges[cnt].w = w;
    edges[cnt].next = head[u];
    head[u] = cnt++;
}

void dfs1(int u, int fa) {
    mx[u] = smx[u] = mxson[u] = smxson[u] = 0;
    for (int i = head[u]; ~i; i = edges[i].next) {
        int v = edges[i].to;
        if(v == fa) continue;
        dfs1(v, u);
        if(mx[v] + edges[i].w > smx[u]) {
            smx[u] = mx[v]+edges[i].w;
            smxson[u] = v;
            if(smx[u] > mx[u]) {
                swap(mx[u], smx[u]);
                swap(mxson[u], smxson[u]);
            }
        }
        //cout<<u<<" "<<v<<" "<<mx[u]<<" "<<smx[u]<<endl;
    }
    return ;
}

void dfs2(int u, int fa) {
    for(int i = head[u]; ~i; i = edges[i].next) {
        int v = edges[i].to;
        if(v == fa) continue;
        if(v == mxson[u]) {
            //cout<<smx[v]<<" "<<edges[i].w<<" "<<smx[u]<<endl;
            if(smx[u] + edges[i].w > smx[v]) {
                smx[v] = edges[i].w+smx[u];
                smxson[v] = u;
                if(smx[v] > mx[v]) {
                    swap(smx[v], mx[v]);
                    swap(mxson[v], smxson[v]);
                }
            }
        } else {
            if(mx[u] + edges[i].w > smx[v]) {
                smx[v] = edges[i].w+mx[u];
                smxson[v] = u;
                //cout<<2<<" "<<u<<" "<<v<<endl;
                if(smx[v] > mx[v]) {
                    swap(smx[v], mx[v]);
                    swap(mxson[v], smxson[v]);
                }
            }
        }
        dfs2(v, u);
    }
}

int log2n[maxn];
int mx_st[maxn][20], mn_st[maxn][20];
void RMQ_Init(int n) {
    log2n[0] = -1;
    for(int i = 1; i <= n; ++i) {
        log2n[i] = ((i&(i-1)) == 0) ? log2n[i-1]+1 : log2n[i-1];
        mx_st[i][0] = mx[i]; mn_st[i][0] = mx[i];
    }
    for(int j = 1; j <= log2n[n]; j++) {
        for(int i = 1; i+(1<<j)-1 <= n; i++) {
            mx_st[i][j] = max(mx_st[i][j-1], mx_st[i+(1<<(j-1))][j-1]);
            mn_st[i][j] = min(mn_st[i][j-1], mn_st[i+(1<<(j-1))][j-1]);
        }
    }
}
int query(int l, int r) {
    int k = log2n[r-l+1];
    return max(mx_st[l][k], mx_st[r-(1<<k)+1][k])-min(mn_st[l][k], mn_st[r-(1<<k)+1][k]);
}

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m) && n+m) {
        cnt = 0;
        memset(head, -1, sizeof(head));
        for (int i = 1; i < n; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
            addedge(v, u, w);
        }

        //debug;
        dfs1(1, -1);
        //debug;
        dfs2(1, -1);
        //debug;

        RMQ_Init(n);

        while (m--) {
            int q;
            scanf("%d", &q);
            int ans = 0, index = 1;
            for (int i = 1; i <= n; i++) {
                while (index <= i && query(index, i) > q) index++;
               // cout<<index<<" "<<i<<endl;
                ans = max(ans, i - index + 1);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}