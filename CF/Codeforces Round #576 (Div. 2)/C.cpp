//
// Created by mile on 2019/7/30.
//
//Codeforces Round #576 (Div. 2) C

#include <bits/stdc++.h>

#define pb push_back
#define ps push
#define mp make_pair
using namespace std;
const int maxn = 400005;
typedef long long ll;

int num[maxn], pre[maxn];
vector<pair<int, int> > st;

int main()
{
    int n, I;
    scanf("%d%d", &n, &I);
    int k = I*8/n;
    if(k >= 19) {
        cout<<0<<endl;
        return 0;
    }
    int mmx = 1<<k;
    for(int i = 1; i <= n; i++) scanf("%d", &num[i]);
    sort(num+1, num+n+1);
    int cnt = 0;
    st.pb(mp(-1,0));
    for(int i = 1; i <= n; i++) {
        if(num[i] == st.back().first) st.back().second++;
        else st.pb(mp(num[i], 1)), cnt++;
    }
    for(int i = 1; i <= cnt; i++) {
        pre[i] = pre[i-1]+st[i].second;
    }
    int sum = 0, ans = 0x3f3f3f3f;
    if(cnt <= mmx) {
        cout<<0<<endl;
        return 0;
    }
    for(int i = mmx; i <= cnt; i++) {
        ans = min(ans, n-(pre[i]-pre[i-mmx]));
    }
    cout<<ans<<endl;
    return 0;
}
