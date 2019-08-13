#include <bits/stdc++.h>

using namespace std;

vector<int> ve;
set<int> se;
int cnt[200005];

bool cmp (int a, int b)
{
    return cnt[a] < cnt[b];
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int m;
        se.clear();
        //memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= n; i++) cnt[i] = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &m);
            se.insert(m);
            cnt[m]++;
        }
        if(n == 1)
        {
            cout<<1<<endl;
            continue;
        }
        for(auto it : se)
        {
            //cout<<it<<endl;
            ve.push_back(it);
        }
        sort(ve.begin(), ve.end(), cmp);
        int flag = INT_MAX;
        int ans = 0;
        for(auto it = ve.end()-1; it >= ve.begin(); it--)
        {
            //cout<<flag<<" "<<cnt[*it]<<endl;
            if(flag > cnt[*it]) ans += cnt[*it], flag = cnt[*it];
            else if(flag == cnt[*it]) flag = cnt[*it]-1, ans += flag;
            else if(flag > 0 && flag < cnt[*it]) ans += --flag;
        }
        cout<<ans<<endl;
        ve.clear();
    }
    return 0;
}

