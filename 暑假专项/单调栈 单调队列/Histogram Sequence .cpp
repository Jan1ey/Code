//
// Created by mile on 2019/7/29.
//
//gym 102059j
//二分+单调栈+优先队列

#include <bits/stdc++.h>

#define ps push
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn = 300005;
typedef long long ll;

struct Node {
    ll id, h, w;
    Node() {}
    Node(ll a, ll b, ll c) : id(a), h(b), w(c) {}
    bool operator < (const Node& a) const {
        return h*w > a.h*a.w;
    }
};

struct Histogram {
    ll n, L, R, sumlen, h[maxn], l[maxn], r[maxn], st[maxn];

    ll init(int n) {
        this->n = n;
        sumlen = 0;
        for(int i = 1; i <= n; i++) scanf("%I64d", &h[i]), sumlen += h[i], l[i] = 1, r[i] = n;
        scanf("%I64d%I64d", &L, &R);
        int tail = 0;
        for(int i = 1; i <= n+1; i++) {
            while (tail >= 1 && h[st[tail]] > h[i]) {
                r[st[tail]] = i-1;
                l[i] = l[st[tail]];
                tail--;
            }
            if(tail) l[i] = st[tail]+1;
            st[++tail] = i;
        }
    }

    ll getnum(ll x, ll y) {
        x = max(1ll, y-x+1);
        return (y+x)%2 == 0 ? (y+x)/2*(y-x+1) : (y-x+1)/2*(y+x);
    }

    ll getlen(ll x, ll y, ll z, ll len) {
        return max(0ll, z-y-len+2)-max(0ll, z-x-len+1)-max(0ll, x-y-len+1);
    }

    ll solve(ll x) {
        ll sum = 0;
        for(int i = 1; i <= n; i++) {
            if(h[i] > x) continue;
            ll len = r[i]-l[i]+1;
            sum += getnum(x/h[i], len)-getnum(x/h[i], r[i]-i)-getnum(x/h[i], i-l[i]);
        }
        return sum;
    }

    ll binary_search(ll L, ll& ans) {
        ll lr = 1, rr = sumlen;
        while(lr < rr) {
            long long mid = (lr+rr)>>1;
            long long val = solve(mid);
            if(val < L) {
                lr = mid+1;
            } else {
                rr = mid;
            }
        }
        ans = lr;
        return solve(lr);
    }

    void work() {
        ll ans = 0;
        ll tmp = binary_search(L, ans);
        while(L <= R && L <= tmp) {
            printf("%I64d ", ans);
            L++;
        }
        priority_queue<Node> Q;
        for(int i = 1; i <= n; i++) Q.ps(Node(i, h[i], ans/h[i]+1));
        Node nxt;
        while(L <= R) {
            nxt = Q.top();
            Q.pop();
=            if(nxt.id >= 300005 || nxt.id <= 0) break;
            ll tlen = getlen(nxt.id, l[nxt.id], r[nxt.id], nxt.w);
            if(!tlen) continue;
            while(tlen > 0 && L <= R) {
                printf("%I64d ", nxt.h*nxt.w);
                tlen--;
                L++;
            }
            ++nxt.w;
            Q.ps(nxt);
        }
    }
};
Histogram ac;

int main()
{
    ll n;
    scanf("%I64d", &n);
    ac.init(n);
    ac.work();
    return 0;
}