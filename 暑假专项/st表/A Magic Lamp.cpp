#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char dig[1005];
int ans[1005];
int st[1005][30];

int main()
{
    int k;
    while(~scanf("%s%d", dig, &k))
    {
        int n = strlen(dig);
        if(k > n)
        {
            puts("0");
            continue;
        }
        else if(k <= 0)
        {
            puts(dig);
            continue;
        }
        for(int i = 0; i < n; i++)
        {
            st[i][0] = dig[i]-'0';
        }
        for(int j = 1; 1<<j <= n; j++)
        {
            for(int i = 0; i+(1<<j)-1 < n; i++)
                st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
        k = n-k;
        int a = 0, b = n-k, cnt = 0;
        while(k--)
        {
            int m = log(b-a+1.0)/log(2.0);
            int s = min(st[a][m], st[b-(1<<m)+1][m]);
            ans[cnt++] = s;
            //cout<<a<<" "<<b<<endl;
            for(int i = a; i <= b; i++)
            {
                if(dig[i] == s+'0')
                {
                    a = i+1, b++;
                    break;
                }
            }
        }
        int flag = cnt;
        for(int i = 0; i < cnt; i++)
        {
            if(ans[i] != 0)
            {
                flag = i;
                break;
            }
        }
        if(flag == cnt) puts("0");
        else
        {
            for(int i = flag; i < cnt; i++)
            {
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
