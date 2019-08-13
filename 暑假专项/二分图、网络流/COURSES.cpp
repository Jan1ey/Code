#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int maps[305][305];
int p, n;
int f[305];
int vis[305];

bool dfs(int x)
{
    for(int i = 1; i <= n; i++)
    {
        if(maps[x][i] && !vis[i])
        {
            vis[i] = 1;
            if(f[i] == 0 || dfs(f[i]))
            {
                f[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
    memset(maps, 0, sizeof(maps));
    memset(f, 0, sizeof(f));
    scanf("%d%d", &p, &n);
    for(int i = 1; i <= p; i++)
    {
        int m;
        scanf("%d", &m);
        for(int j = 0; j < m; j++)
        {
            int u;
            scanf("%d", &u);
            maps[i][u] = 1;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= p; i++)
    {
        memset(vis, 0, sizeof(vis));
        if(dfs(i)) cnt++;
    }
    if(cnt == p) puts("YES");
    else puts("NO");
    }
    return 0;
}
