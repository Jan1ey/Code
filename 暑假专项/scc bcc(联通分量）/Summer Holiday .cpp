#include <bits/stdc++.h>

using namespace std;

stack<int> st;
vector<int> edge[20005];
int low[20005], dfn[20005], vis[20005], degree[20005], money[20005], cost[20005];
int visit[20005];
int sum, cnt, n, m;

void tarjan(int u)
{
    low[u] = dfn[u] = ++cnt;
    st.push(u);
    for(auto it : edge[u])
    {
        if(!dfn[it])
        {
            tarjan(it);
            low[u] = min(low[u], low[it]);
        }
        else if(!vis[it])
        {
            low[u] = min(low[u], dfn[it]);
        }
    }
    if(low[u] == dfn[u])
    {
        //cout<<u<<endl;
        sum++;
        while(true)
        {
            int x = st.top(); st.pop();
            vis[x] = sum;
            if(x == u) break;
        }
    }
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        sum = 0, cnt = 0;
        for(int i = 1; i <= n; i++) scanf("%d", &cost[i]);
        memset(vis, 0, sizeof(vis));
        memset(dfn, 0, sizeof(dfn));
        memset(degree, 0, sizeof(degree));
        for(int i = 1; i <= n; i++) edge[i].clear(), money[i] = INT_MAX;
        for(int i = 1; i <= m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            edge[u].push_back(v);
        }
        for(int i = 1; i <= n; i++)
        {
            if(!dfn[i]) tarjan(i);
        }
        int cn = 0, ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(auto j : edge[i])
            {
                if(vis[i] != vis[j]) degree[vis[j]]++;
            }
        }
        for(int i = 1; i <= n; i++) money[vis[i]] = min(money[vis[i]], cost[i]);
        for(int i = 1; i <= sum; i++)
        {
            if(cn == sum) break;
            if(!degree[i])
            {
                ans += money[i], cn++;
            }
        }
        printf("%d %d\n", cn, ans);
    }
    return 0;
}
