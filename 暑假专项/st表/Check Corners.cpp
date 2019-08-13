#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 300+11;

int n, m;
int st[maxn][maxn][9][9];

void init()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &st[i][j][0][0]);
    for(int r = 0; (1<<r) <= n; ++r) {
        for(int c = 0; (1<<c) <= m; ++c) {
            if(r == 0 && c == 0) continue;
            for(int i = 1; i+(1<<r)-1 <= n; ++i) {
                for(int j = 1; j+(1<<c)-1 <= m; ++j) {
                    if(r) {
                        st[i][j][r][c] = max(st[i][j][r-1][c], st[i+(1<<(r-1))][j][r-1][c]);
                    }else {
                        st[i][j][r][c] = max(st[i][j][r][c-1], st[i][j+(1<<(c-1))][r][c-1]);
                    }
                }
            }
        }
    }
}

void query(int x1, int y1, int x2, int y2)
{
    int kx = (int)(log(x2-x1+1.0)/log(2.0));
    int ky = (int)(log(y2-y1+1.0)/log(2.0));
    int m1 = st[x1][y1][kx][ky];
    int m2 = st[x2-(1<<kx)+1][y1][kx][ky];
    int m3 = st[x1][y2-(1<<ky)+1][kx][ky];
    int m4 = st[x2-(1<<kx)+1][y2-(1<<ky)+1][kx][ky];
    int tmp = max(m1,max(m2,max(m3, m4)));
    printf("%d ", tmp);
    if(st[x1][y1][0][0] == tmp || st[x1][y2][0][0] == tmp || st[x2][y1][0][0] == tmp || st[x2][y2][0][0] == tmp) printf("yes\n");
    else printf("no\n");
}

int main()
{
    int l1, l2, r1, r2, q;
    while(scanf("%d%d", &n, &m)!=EOF)
    {
        init();
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
            query(l1, r1, l2, r2);
        }
    }
    return 0;
}
