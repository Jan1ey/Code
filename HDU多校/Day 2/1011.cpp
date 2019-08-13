//
// Created by mile on 2019/7/24.
//
//主席树 遍历区间寻找符合三角形三边关系的第k大、k+1大、k+2大（k from 1 to len）
/*

#include <bits/stdc++.h>
#define mid (l+r)/2
#define ll long long
using namespace std;

const int N = 200010;
int n, q, m, cnt = 0;
int a[N], b[N], T[N];
int sum[N<<5], L[N<<5], R[N<<5];

inline int build(int l, int r)
{
    int rt = ++ cnt;
    sum[rt] = 0;
    if (l < r){
        L[rt] = build(l, mid);
        R[rt] = build(mid+1, r);
    }
    return rt;
}

inline int update(int pre, int l, int r, int x)
{
    int rt = ++ cnt;
    L[rt] = L[pre]; R[rt] = R[pre]; sum[rt] = sum[pre]+1;
    if (l < r){
        if (x <= mid) L[rt] = update(L[pre], l, mid, x);
        else R[rt] = update(R[pre], mid+1, r, x);
    }
    return rt;
}

inline int query(int u, int v, int l, int r, int k)
{
    if (l >= r) return l;
    int x = sum[L[v]] - sum[L[u]];
    if (x >= k) return query(L[u], L[v], l, mid, k);
    else return query(R[u], R[v], mid+1, r, k-x);
}

bool check(ll a, ll b, ll c) {
    if(a+b>c && a+c>b && b+c > a && a-b<c && a-c<b && b-c<a) return 1;
    else return 0;
}

int main()
{
    while(~scanf("%d%d", &n, &q)) {
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b + 1, b + 1 + n);
        m = unique(b + 1, b + 1 + n) - b - 1;
        T[0] = build(1, m);
        for (int i = 1; i <= n; i++) {
            int t = lower_bound(b + 1, b + 1 + m, a[i]) - b;
            T[i] = update(T[i - 1], 1, m, t);
        }
        while (q--) {
            int x, y, z;
            long long ans = -1;
            scanf("%d%d", &x, &y);
            for (int i = y - x + 1; i >= 3; i--) {
                int c1 = query(T[x - 1], T[y], 1, m, i);
                int c2 = query(T[x - 1], T[y], 1, m, i - 1);
                int c3 = query(T[x - 1], T[y], 1, m, i - 2);
                if (check((ll) b[c1], (ll) b[c2], (ll) b[c3])) {
                    ans = 1ll * b[c1] + 1ll * b[c2] + 1ll * b[c3];
                    break;
                }
            }
            if (ans == 0) puts("-1");
            else printf("%lld\n", ans);
        }
    }
    return 0;
}
*/