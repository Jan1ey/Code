#include <bits/stdc++.h>

using namespace std;

vector<int> ve[200005];
long long sum[200005];
long long ans;
int n;

void dfs(int a, int b)
{
    sum[a] = 1;
    for(auto it : ve[a])
    {
        if(it == b) continue;
        dfs(it, a);
        sum[a] += sum[it];
    }
    return ;
}

void dfs(int a, int b, long long c)
{
    ans = max(ans, c);
    for(auto it : ve[a])
    {
        if(it == b) continue;
        dfs(it, a, c+n-sum[it]*2);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        ve[l].push_back(r);
        ve[r].push_back(l);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        ans += sum[i];
    dfs(1, 0, ans);
    cout<<ans<<endl;
    return 0;
}
