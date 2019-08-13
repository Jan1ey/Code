//
// Created by mile on 2019/7/30.
//
//求割顶、桥

#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;
int dfs_clock = 0;

int pre[maxn], low[maxn], isbridge[maxn][maxn];
bool iscut[maxn];
vector<int> G[maxn];

int dfs(int u, int fa) {                   //u在dfs树中的父节点是fa
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;                         //子节点数目
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(!pre[v]) {                      //没有访问过v
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);        //用后代的low函数更新u的low函数
            if(lowv >= pre[u]) {
                iscut[u] = true;
            }
            if(lowv > pre[u]) {
                isbridge[u][v] = isbridge[v][u] = 1;
            }
        } else if(pre[v] < pre[u] && v != fa) {
            lowu = min(lowu, pre[u]);        //用反向边更新u的low函数
        }
    }
    if(fa < 0 && child == 1) iscut[u] = 0;
    low[u] = lowu;
    return lowu;
}

int main() {
    memset(pre, 0, sizeof(pre));    //pre数组清零
    for(int i = 1; i <= maxn; i++) {
        if(!pre[i]) dfs(i, -1);
    }
}