//
// Created by mile on 2019/7/29.
//
//HDU多校2019 Day3 T7
//离散化+线段树
//输出格式：每个数字后面有一个空格， 每行输出后面一个空格

#include <bits/stdc++.h>

#define lid id<<1
#define rid id<<1|1
using namespace std;
typedef long long ll;
const int maxn = 200005;

struct Num {
    int cnt, val, id;
};

struct Node {
    int l, r, id, count;
    ll sum;
};

bool cmp1(Num a, Num b) {
    return a.val == b.val ? a.id < b.id : a.val < b.val;
}

bool cmp2(Num a, Num b) {
    return a.id < b.id;
}

struct SegmentTree {
    ll n, m;
    Num num[maxn];
    Node tr[maxn<<2];

    void init(int n, int m) {
        this->n = n, this->m = m;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &num[i].val);
            num[i].id = i;
        }
        sort(num+1, num+n+1, cmp1);
        for(int i = 1; i <= n; i++) num[i].cnt = i;
        sort(num+1, num+n+1, cmp2);
        build(1, 1, n);
    }

    void build(int id, int l, int r) {
        tr[id].l = l, tr[id].r = r;
        tr[id].sum = tr[id].count = 0;
        if(tr[id].l == tr[id].r) {
            return ;
        }
        int mid = (l+r)>>1;
        build(lid, l, mid);
        build(rid, mid+1, r);
        tr[id].sum = tr[lid].sum + tr[rid].sum;
    }

    void update(int id, int pos, int cnt) {
        if(tr[id].l == tr[id].r && tr[id].l == pos) {
            tr[id].sum = num[cnt].val; tr[id].count = 1;
            return ;
        }
        int mid = (tr[id].l + tr[id].r)>>1;
        if(pos <= mid) update(lid, pos, cnt);
        else update(rid, pos, cnt);
        tr[id].sum = tr[lid].sum+tr[rid].sum;
        tr[id].count = tr[lid].count+tr[rid].count;
    }

    int query(int id, ll sum) {
        if(tr[id].sum <= sum) return tr[id].count;
        if(tr[id].l == tr[id].r) return tr[id].sum <= sum;
        if(tr[lid].sum >= sum) return query(lid, sum);
        else return tr[lid].count+query(rid, sum-tr[lid].sum);
    }

    void solve() {
        for(int i = 1; i <= n; i++) {
            printf("%d ",i-1-query(1, m-num[i].val));
            update(1,num[i].cnt, num[i].id);
        }
        puts("");
    }
};

SegmentTree tree;


int main()
{
    int Q;
    scanf("%d", &Q);
    while(Q--) {
        ll n, m;
        scanf("%lld%lld", &n, &m);
        tree.init(n, m);
        tree.solve();
    }
    return 0;
}

