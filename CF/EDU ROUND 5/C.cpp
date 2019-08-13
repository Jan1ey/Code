#include <bits/stdc++.h>

using namespace std;

int n, m;
int cnt[1000005];
char maps[1005][1005];
int vis[1005][1005];
int cl[1005][1005];
int col;
int dir[][2] = {1,0,-1,0,0,1,0,-1};

void dfs(int x, int y, int col)
{
    vis[x][y] = 1;
    cnt[col]++;
    cl[x][y] = col;
    for(int i = 0; i < 4; i++)
    {
        int xx = x+dir[i][0], yy = y+dir[i][1];
        //cout<<col<<" "<<xx<<" "<<yy<<endl;
        if(xx <= 0 || xx > n || yy <= 0 || yy > m || maps[xx][yy] == '*' || vis[xx][yy]) continue;
       dfs(xx, yy, col);
    }
}

int main()
{
    col = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%s", maps[i]+1);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(maps[i][j] == '.' && !vis[i][j]) col++, dfs(i, j, col);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(maps[i][j] == '*')
            {
                vector<int> se;
                for(int k = 0; k < 4; k++)
                {

                    int x = i+dir[k][0], y = j+dir[k][1];
                    if(maps[x][y] == '.')
                    {
                        se.push_back(cl[x][y]);
                    }
                }
                sort(se.begin(), se.end());
                auto t = unique(se.begin(), se.end());
                se.erase(t, se.end());
                int ans = 0;
                for(auto it : se)
                {
                    ans += cnt[it];
                }
                maps[i][j] = (ans+1)%10+'0';
            }
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%s\n", maps[i]+1);
    return 0;
}

/*10 10
*.*...*.**
..*...*.**
.**.***...
....*.*.**
***....***
.*..*...*.
.***.*..*.
.*****.*.*
*.***.*...
..*..*....*/
