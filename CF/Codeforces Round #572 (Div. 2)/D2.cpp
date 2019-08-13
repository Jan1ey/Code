#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

struct Edge
{
    int u, v, x;
    Edge(){};
    Edge(int a, int b, int c)
    {
        u = a, v = b, x = c;
    }
};

vector<Edge> s, ans;
vector<int> edge[1005];
int d[1005];

vector<int> dfs(int u, int v)
{
    if(d[u] == 1)
    {
        vector<int> need(1);
        need[0] = u;
        return need;
    }
    vector<int> need;
    vector<int> tmp;
    for(auto it : edge[u])
    {
        if(it == v) continue;
        tmp = dfs(it, u);
        if((int)need.size() < 2)
            need.push_back(tmp[0]);
    }
    return need;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int u, v, x;
        scanf("%d%d%d", &u, &v, &x);
        d[u]++;
        d[v]++;
        edge[u].push_back(v);
        edge[v].push_back(u);
        s.push_back(Edge(u, v, x));
    }
    for(int i = 1; i <= n; i++)
    {
        if(d[i] == 2)
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    if(n == 2)
    {
        printf("1\n");
        printf("%d %d %d\n", s[0].u, s[0].v, s[0].x);
        return 0;
    }
    for(int i = 1; i <= n-1; i++)
    {
        int u, v, x;
        u = s[i-1].u, v = s[i-1].v, x = s[i-1].x;
        if(d[u] == 1 || d[v] == 1)
        {
            if(d[u] == 1) swap(u, v);
            vector<int> op;
            op = dfs(u, v);
            ans.push_back(Edge(v, op[0], x/2));
            ans.push_back(Edge(v, op[1], x/2));
            ans.push_back(Edge(op[0], op[1], -x/2));
            continue;
        }
        vector<int> op1, op2;
        op1 = dfs(u, v);
        op2 = dfs(v, u);
        ans.push_back(Edge(op1[0], op2[0], x/2));
        ans.push_back(Edge(op1[1], op2[1], x/2));
        ans.push_back(Edge(op1[0], op1[1], -x/2));
        ans.push_back(Edge(op2[0], op2[1], -x/2));
    }
    printf("%d\n", (int)ans.size());
    for(auto it : ans)
    {
       cout<<it.u<<" "<<it.v<<" "<<it.x<<endl;
    }
    return 0;
}
