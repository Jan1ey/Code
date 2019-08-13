#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> ve[200005];
int siz[200005];
long long ans;

void dfs(int a, int b)
{
    siz[a] = 1;
    for(auto it : ve[a])
    {
        if(it == b) continue;
        dfs(it, a);
        siz[a] += siz[it];
    }
}

void dfs2(int a, int b, long long s)
{
    ans = max(ans, s);
    //cout<<s<<endl;
    for(auto it : ve[a])
    {
        if(it == b) continue;
        //cout<<it<<" "<<s<<" "<<n<<" "<<siz[it]<<endl;
        dfs2(it, a, (s-siz[it])+(n-siz[it]));
    }
    return ;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        ans += siz[i];
    //cout<<ans<<endl;
    dfs2(1, 0, ans);
    cout<<ans<<endl;
    return 0;
}
