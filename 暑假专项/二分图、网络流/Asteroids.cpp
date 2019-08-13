#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int maps[505][505];
int f[505], vis[505];
int n, k;

bool dfs(int x)
{
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i] && maps[x][i])
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
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= k; i++)
    {
        int r, c;
        scanf("%d%d", &r, &c);
        maps[r][c] = 1;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        if(dfs(i)) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
