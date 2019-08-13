//
// Created by mile on 2019/7/21.
//
//y = 1-i (mod a[i])
// b[i] (mod a[i]) = b[j] (mod a[j])
// y = b[i] + k * a[i] = b[j] + k * a[j]
//k * a[i] - k * a[j] = b[j] - b[i]
/*
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a[10005], b[10005];

ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a%b);}
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if(!b) {x = 1, y = 0; return a;}
    ll ans = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return ans;
}

int main()
{
    cin.tie(0);
    ll n, m, k;
    cin>>n>>m>>k;
    for(int i = 1; i <= k; i++) cin>>a[i];
    ll lcm = 1;
    for(int i = 1; i <= k; i++)
        lcm = lcm/gcd(lcm, a[i])*a[i];
    for(int i = 1; i <= k; i++) b[i] = 1-i;
    ll a1 = a[1], b1 = b[1], xx, yy;
    for(int i = 2; i <= k; i++)
    {
        ll d = exgcd(a1, a[i], xx, yy);
        if((b[i]-b1)%d) {puts("NO"); return 0;}
        ll r = a[i]/d;
        xx = (b[i]-b1)/d*xx;
        xx = (xx%r+r)%r;
        b1 += xx*a1;
        a1 = a1/d*a[i];
        b1 %= a1;
    }
    if(b1 < 0) b1 += a1;
    if(lcm > n) {puts("NO"); return 0;}
    else {
        //cout<<b1<<endl;
        if (b1 < 0) { puts("NO"); return 0; }
        if (b1 == 0) { b1 = lcm; }
        if (b1 + k - 1 > m) {
            puts("NO");
            return 0;
        }
        //cout<<lcm<<" "<<b1<<endl;
        for (int i = 1; i <= k; i++)
            if (gcd(lcm, b1 + i - 1) != a[i]) {
                puts("NO");
                return 0;
            }
    }
    puts("YES");
    return 0;
}
*/