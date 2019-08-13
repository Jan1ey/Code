#include <bits/stdc++.h>

using namespace std;
const int maxn = 200005;

int cnt, num, n, m;
int dfn[maxn], low[maxn], sz[maxn], be[maxn], scc[maxn], vis[maxn];
stack<pair<int, int> > st;
vector<pair<int, int> > edge[maxn];
vector<int> tmp;
set<int> ans;

int tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++cnt;
    for(auto it : edge[u])
    {
        int nx = it.second;
        int ny = it.first;
        if(vis[nx]) continue;
        vis[nx] = 1;
        st.push(it);
        if(!dfn[ny])
        {
            tarjan(ny, u);
            low[u] = min(low[u], low[ny]);
            if(low[ny] >= dfn[u])
            {
                num++;
                tmp.clear();
                while(true)
                {
                    pair<int, int> x = st.top();
                    st.pop();
                    if(be[x.first] != num)
                    {
                        sz[num]++;
                        be[x.first] = num;
                    }
                    scc[x.second] = num;
                    tmp.push_back(x.second);
                    if(x.second == nx) break;
                }
                if(sz[num] > 1 && tmp.size() == sz[num])
                {
                    for(auto i : tmp)
                    {
                        ans.insert(i);
                    }
                }
            }
        }
        else if(ny != fa)
            low[u] = min(low[u], dfn[ny]);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        edge[u].push_back(make_pair(v, i));
        edge[v].push_back(make_pair(u, i));
    }
    for(int i = 1; i <= n; i++)
    {
        if(!dfn[i]) tarjan(i, i);
    }
    cout<<ans.size()<<endl;
    //sort(ans, 0, sizeof(ans));
    for(auto f : ans)
    {
        printf("%d ", f);
    }
    printf("\n");
    return 0;
}
