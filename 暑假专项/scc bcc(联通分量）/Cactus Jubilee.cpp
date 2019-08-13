#include <bits/stdc++.h>

#define pb push_back
#define ps push
using namespace std;
const int maxn =  50005;

int n, m, cnt, num;
int fa[maxn], sz[maxn];
int dfn[maxn], low[maxn];
stack<pair<int, int> > st;
vector<int> edge[maxn];
vector<pair<int, int> > bcc[maxn];

int findx(int x)
{
    if(fa[x] == x) return x;
    else return fa[x] = findx(fa[x]);
}

void link(int a, int b)
{
    a = findx(a), b = findx(b);
    if(a == b) return ;
    fa[b] = a;
    sz[a] += sz[b];
}

long long ans = 0;
void tarjan(int u, int v)
{
    dfn[u] = low[u] = ++cnt;
    sz[u] = 1;
    for(auto nx : edge[u])
    {
        if(nx == v) continue;
        pair<int, int> last = make_pair(u, nx);
        if(!dfn[nx])
        {
            st.push(last);
            tarjan(nx, u);
            sz[u] += sz[nx];
            low[u] = min(low[u], low[nx]);
            if(low[nx] > dfn[u]) ans += sz[nx]*1ll*(n-sz[nx])-1;
            if(low[nx] >= dfn[u])
            {
                num++;
                while(true)
                {
                    pair<int, int> x = st.top(); st.pop();
                    bcc[num].pb(x);
                    if(x == last) break;
                }
            }
        }
        else if(nx != v)
        {
            if(dfn[nx] < low[u])
                st.ps(last), low[u] = min(dfn[nx], low[u]);
        }
    }
}

int main()
{
    freopen("cactus.in", "r", stdin);
    freopen("cactus.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        int t, u, v;
        scanf("%d", &t);
        scanf("%d%d", &u, &v);
        //cout<<t<<endl;
        edge[u].pb(v), edge[v].pb(u);
        for(int j = 3; j <= t; j++)
        {
            scanf("%d", &u);
            //cout<<u<<endl;
            edge[u].pb(v), edge[v].pb(u);
            v = u;
        }
    }

    for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i,-1);
    for(int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
    for(int i = 1; i <= num; i++)
    {
        if(bcc[i].size() == 1)
        {
            //cout<<bcc[i][0].first<<" "<<bcc[i][0].second<<endl;
            link(bcc[i][0].first, bcc[i][0].second);
        }
    }
    long long sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(fa[i] == i)
        {
            //cout<<i<<" "<<sum<<endl;
            sum += sz[i]*1ll*(sz[i]-1)/2-(sz[i]-1);
        }
    }
    //cout<<sum<<endl;
    for(int i = 1; i <= num; i++)
    {
        if(bcc[i].size() == 1) continue;
        long long tmp = sum, tans = 0;
        for(auto j : bcc[i])
        {
            int a = findx(j.first);
            tmp -= sz[a]*1ll*(sz[a]-1)/2-(sz[a]-1);
            tans += sz[a];
        }
        ans += (tmp+tans*1ll*(tans-1)/2-(tans-1)-1)*1ll*bcc[i].size();
    }
    printf("%lld\n", ans);
    return 0;
}
