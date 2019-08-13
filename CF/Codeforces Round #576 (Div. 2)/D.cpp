//
// Created by mile on 2019/7/30.
//
//Codeforces Round #576 (Div. 2) D

#include <bits/stdc++.h>

#define lid id<<1
#define rid id<<1|1
using namespace std;
typedef long long ll;
const int maxn = 200005;

int num[maxn], lazy[maxn<<2];

struct SegmentTree {
    ll n, m;

    void init() {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &num[i]);
        }
        scanf("%d", &m);
        while(m--) {
            int op;
            scanf("%d", &op);
            if(op == 1) {
                int x, y;
                scanf("%d%d", &x, &y);
                update(1, 1, n, x, y);
            } else {
                int x;
                scanf("%d", &x);
                lazy[1] = max(x, lazy[1]);
            }
        }
    }

    void update(int id,int l, int r, int pos, int cnt) {
        if(l == r && l == pos) {
            num[l] = cnt;
            lazy[id] = 0;
            return ;
        }
        lazy[lid] = max(lazy[lid], lazy[id]);
        lazy[rid] = max(lazy[rid], lazy[id]);
        lazy[id] = 0;
        int mid = (l + r)>>1;
        if(pos <= mid) update(lid, l, mid, pos, cnt);
        else update(rid, mid+1, r, pos, cnt);

    }

    int query(int id, int l, int r, int pos) {
        if(l == r && l == pos)
        {
           return num[l] = max(num[l], lazy[id]);
        }
        lazy[lid] = max(lazy[lid], lazy[id]);
        lazy[rid] = max(lazy[rid], lazy[id]);
        lazy[id] = 0;
        int mid = (l + r)>>1;
        if(pos <= mid) query(lid, l, mid, pos);
        else query(rid, mid+1, r, pos);

    }

    void solve() {
        for(int i = 1; i <= n; i++) {
            printf("%d ", query(1, 1, n, i));
        }
    }
};

SegmentTree tree;


int main()
{
    tree.init();
    tree.solve();
    return 0;
}
