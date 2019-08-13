//
// Created by mile on 2019/7/20.
//
/*#include <bits/stdc++.h>

using namespace std;

char ch[1005][1005];
int num[1005][1005];
int l[1005], r[1005];
pair<int, int> st[1005];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%s", ch[i]+1);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            if(ch[i][j] != '0') num[i][j] = ch[i][j]-'0'+num[i-1][j];
    }
    int ans1, ans2, sz1, sz2;
    ans1 = ans2 = sz1 = sz2 = 0;
    r[n] = n+1;
    int a, b;
    a = 0, b = 0;
    for(int i = 1; i <= n; i++)
    {
        ans1 = ans2 = 0;
        int hd1 = 1, bk1 = 0;
        int hd2 = 1, bk2 = 0;
        int k = 1;
        while(num[i][k] == 0) k++ ;
        st[0] = make_pair(0,k-1);
        for(int j = 1; j <= m; j++)
        {
            //if(num[i][j] == 0) continue;
            l[j] = 0;
            while(hd1 <= bk1 && num[i][j] <= st[bk1].first) bk1--;
            l[j] = st[bk1].second;st[++bk1] = make_pair(num[i][j], j);
            //cout<<l[j]<<" ";
        }
        //cout<<endl;
        k = m;
        while(num[i][k] == 0) k--;
        st[0] = make_pair(0,k+1);
        for(int j = m; j >= 1; j--)
        {
            //if(num[i][j] == 0) continue;
            r[j] = 0;
            while(hd2 <= bk2 && num[i][j] <= st[bk2].first) bk2--;
            r[j] = st[bk2].second,st[++bk2] = make_pair(num[i][j], j);
            //cout<<r[j]<<" ";
        }
        //cout<<endl;
        for(int j = 1; j <= m; j++)
        {
            if(num[i][j] == 0) continue;
            int tmp = (r[j]-l[j]-1)*num[i][j];
            //cout<<num[i][j]<<endl;
            //cout<<i<<" "<<j<<endl;
            if(tmp > ans1) {
                ans2 = ans1;
                ans1 = tmp;
                if (ans1 - num[i][j] > ans2) ans2 = ans1 - num[i][j];
                if (ans1 - (r[j] - l[j] - 1) > ans2) ans2 = ans1 - (r[j] - l[j] - 1);
                //cout << ans1 << " " << ans2 << " " << ans1 - num[i][j] << " " << ans1 - (r[j] - l[j] - 1) << endl;
            }
            else if(tmp == ans1) ans2 = ans1;
        }
        //cout<<ans1<<" "<<ans2<<endl;
        if(ans1 == a) b = a;
        else if(ans1 > a) b = a, a = ans1;
        if(ans2 == ans1 && ans1 == a) b = ans2;
        //cout<<a<<" "<<b<<endl;
    }
    cout<<b<<endl;
    return 0;
}*/