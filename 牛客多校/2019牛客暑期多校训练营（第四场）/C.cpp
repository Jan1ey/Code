//
// Created by mile on 2019/7/28.
//

#include <bits/stdc++.h>

namespace solve{
    using namespace std;
    typedef long long ll;

    const int maxn = 3e6+5;
    int n, top, rt, a[maxn], st[maxn], son[maxn][2];
    ll b[maxn];
    void build() {
        top = 0;
        for(int i = 1; i <= n; i++) son[i][0] = son[i][1] = 0;
        for(int i = 1; i <= n; i++) {
            while(top && a[st[top]] > a[i]) son[i][0] = st[top--];
            if(top) son[st[top]][1] = i;
            st[++top] = i;
        }
        rt = st[1];
    }
    ll ans;
    void dfs(int x, int L, int R, ll&mn, ll&mx) {
        ll n1 = 4e18, x1 = -4e18, n2 = 4e18, x2 = -4e18;
        if(son[x][0]) dfs(son[x][0], L, x-1, n1, x1);
        if(son[x][1]) dfs(son[x][1], x+1, R, n2, x2);
        n2 = min(n2, b[x]); x2 = max(x2, b[x]);
        //cout<<x<<" "<<L<<" "<<R<<" "<<x2<<" "<<n2<<x1<<" "<<x2<<endl;
        if(a[x]<0) {
            ans = max(ans, (n2-max(x1, b[L-1]))*a[x]);
        } else {
            ans = max(ans, (x2-min(n1, b[L-1]))*a[x]);
        }
        mn = min(n1, n2), mx = max(x1, x2);
    }
    void work() {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
        build();
        b[0] = 0;
        for(int i = 1; i <= n; i++) b[i] += b[i-1];
        ans = -4e18;
        ll ua, ub;
        dfs(rt, 1, n, ua, ub);
        printf("%lld\n", ans);
    }
}

int main()
{
    solve::work();
    return 0;
}