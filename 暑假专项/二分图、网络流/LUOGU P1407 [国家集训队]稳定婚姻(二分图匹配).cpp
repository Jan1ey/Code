#include <bits/stdc++.h>

using namespace std;

const int maxe = 200005, maxn = 4005*2;

struct Edge
{
    int from, to, nxt;
}edge[maxe*2];

map<string, int> mp;
int head[maxn], match[maxn], vis[maxn];
int n, m, tot;

void addedge(int u, int v)
{
    //cout<<u<<" "<<v<<endl;
    edge[++tot].to = v;
    edge[tot].from = u;
    edge[tot].nxt = head[u];
    head[u] = tot;
}

bool dfs(int x)
{
    //cout<<x<<endl;
    for(int i = head[x]; i; i = edge[i].nxt)
    {
        if(vis[edge[i].to]) continue;
        vis[edge[i].to] = 1;
        //cout<<match[edge[i].to]<<" "<<edge[i].to<<endl;
        if(match[edge[i].to] == 0 || dfs(match[edge[i].to]))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    int cnt = 0;
    string s1, s2;
    for(int i = 1; i <= n; i++)
    {
        cin>>s1>>s2;
        if(!mp[s1]) mp[s1] = ++cnt;
        if(!mp[s2]) mp[s2] = ++cnt;
        match[mp[s1]] = mp[s2];
        match[mp[s2]] = mp[s1];
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; i++)
    {
        cin>>s1>>s2;
        addedge(mp[s1], mp[s2]);
    }
    for(int i = 1; i <= cnt; i += 2)
    {
        memset(vis, 0, sizeof(vis));
        match[match[i]] = 0;
        if(dfs(i)) puts("Unsafe");
        else puts("Safe");
        match[match[i]] = i;
    }
    return 0;
}
