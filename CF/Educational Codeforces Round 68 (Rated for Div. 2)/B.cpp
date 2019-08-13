#include <bits/stdc++.h>

using namespace std;

int l[50005], r[50005];

int main()
{
    int q;
    scanf("%d", &q);
    int cnt = 0;
    while(q--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        char c;
        bool maps[n+1][m+1];
        for(int i = 1; i <= m; i++) r[i] = 0;
        for(int i = 1; i <= n; i++) l[i] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin>>c;
                if(c == '*') l[i]++, r[j]++;
                maps[i][j] = (c == '*');
            }
        }
        int a = n+m;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                int tmp = n+m-1;
                tmp -= l[i]+r[j];
                if(maps[i][j] == 1) tmp++;
                a = min(a, tmp);
            }
        }
        cout<<a<<endl;
    }
    return 0;
}
