//tarjan判断强连通分量
#include <bits/stdc++.h>

using namespace std;

int n, m;
map<string, int> mp;
int u[4005<<1], v[4005<<1], ct[4005<<1];
vector<int> edge[4005<<1];
int dfn[4005<<1], low[4005<<1], vis[4005<<1], in_st[4005<<1], cnt, sum;
stack<int> st;

void tarjan(int u)
{
    dfn[u] = low[u] = ++cnt;
    in_st[u] = 1;
    st.push(u);
    for(auto v : edge[u])
    {
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(in_st[v]) low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u])
    {
        sum++;
        while(true)
        {
            int x = st.top(); st.pop();
            in_st[x] = 0;
            vis[x] = sum;
            if(x == u) break;
        }
    }
}

int main()
{

    cin.tie(0);
    cin>>n;
    string s1, s2;
    int num = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>s1>>s2;
        if(!mp[s1]) mp[s1] = ++num;
        if(!mp[s2]) mp[s2] = ++num;
        u[i] = mp[s1], v[i] = mp[s2];
        edge[mp[s1]].push_back(mp[s2]);
    }
    cin>>m;
    for(int i = 0; i < m; i++)
    {
        cin>>s1>>s2;
        edge[mp[s2]].push_back(mp[s1]);
    }
    for(int i = 1; i < num; i++)
    {
        if(!dfn[i]) tarjan(i);
    }
    for(int i = 1; i < num; i++)
    {
        ct[vis[i]]++;
    }
    for(int i = 1; i < num; i+=2)
    {
        //cout<<vis[i]<<" "<<vis[i+1]<<endl;
        if(ct[vis[i]] > 1) cout<<"Unsafe"<<endl;
        else cout<<"Safe"<<endl;
    }
    return 0;
}
