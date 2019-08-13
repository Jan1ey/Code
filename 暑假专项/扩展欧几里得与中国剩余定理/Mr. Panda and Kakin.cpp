//
// created by mile 2019/07/22
//
// c = f^e mod n
// e * d = 1 mod n
// d
// f = c^d mod n

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll e = (1ll<<30)+3;

ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a%b);}

ll ex_gcd(ll a, ll b, ll &x, ll &y)
{
    if(!b) {x = 1, y = 0; return a;}
    ll ans = ex_gcd(b, a%b, y, x);
    y -= a/b*x;
    return ans;
}

ll multi(ll a, ll b, ll mod)
{
    return (a*b-(ll)((long double)a*b/mod)*mod+mod)%mod;
}

ll qpow(ll a, ll b, ll mod)
{
    ll ans = 1;
    while(b) {
        if(b&1) ans = multi(ans, a, mod);
        a =  multi(a, a, mod);
        b >>= 1;
    }
    return ans;
}

int main()
{
    int t, cnt = 0;
    scanf("%d", &t);
    while(t--)
    {
        ll n, p, q, c, d, x, y;
        scanf("%lld%lld", &n, &c);
        p = sqrt(n);
        while(n%p != 0) p--;
        q = n/p;
        ll r = (p-1)*(q-1);
        ex_gcd(e, r, x, y);
        x = (x%r+r)%r;
        printf("Case %d: %lld\n", ++cnt, qpow(c, x, n));
    }
    return 0;
}