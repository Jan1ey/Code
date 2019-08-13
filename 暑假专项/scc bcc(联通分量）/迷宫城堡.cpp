#include <bits/stdc++.h>

using namespace std;

vector<int> edge[10005];
int dfn[10005], low[10005], vis[10005];
stack<int> st;
int n, m, cnt, sum;

void tarjan(int u)
{
    low[u] = dfn[u] = ++cnt;
    st.push(u);
    for(int i = 0; i < (int)edge[u].size(); i++)
    {
        if(!dfn[edge[u][i]])
        {
            tarjan(edge[u][i]);
            low[u] = min(low[u], low[edge[u][i]]);
        }
        else if(!vis[edge[u][i]])
        {
            low[u] = min(low[u], dfn[edge[u][i]]);
        }
    }
    if(dfn[u] == low[u])
    {
        //ans = max(top, ans);
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
    while(~scanf("%d%d", &n, &m) &&n+m)
    {
        cnt = sum = 0;
        for(int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
        }
        for(int i = 1; i <= n; i++) edge[i].clear();
        memset(vis, 0, sizeof(vis));
        memset(dfn, 0, sizeof(dfn));
        for(int i =1; i <= m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            edge[u].push_back(v);
        }
        for(int i = 1; i <= n; i++)
        {
            if(!dfn[i]) tarjan(i);
        }
        cout<<sum<<endl;
        if(sum == 1) puts("Yes");
        else puts("No");

    }
    return 0;
}
