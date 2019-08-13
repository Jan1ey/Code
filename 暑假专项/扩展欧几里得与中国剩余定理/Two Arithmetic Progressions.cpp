//
// Created by mile on 2019/7/21.
//
//a1 * k + b1 = a2 * l + b2 = x;
//x = b1 (mod a1)
//x = b2 (mod a2)
//x = (b2-b1) (mod a2)
//k1 * a1 = (b2 - b1) (mod a2)
//k1 * a1 + l * a2 = (b2 - b1)
/*
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if(!b) {x = 1, y = 0; return a;}
    ll ans = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return ans;
}

int main()
{
    ll a1, b1, a2, b2, l, r, xx, yy;
    cin>>a1>>b1>>a2>>b2>>l>>r;
    ll d = exgcd(a1, a2, xx, yy);
    if((b2-b1)%d)
    {
        cout<<0<<endl;
        return 0;
    }
    ll x = a2/d;
    xx = (b2-b1)/d*xx;
    xx = (xx%x+x)%x;
    l = max(l, max(b1, b2));
    ll ans = 0, cnt = a1*xx+b1, lcm = a1/d*a2;
    if(l > r)
    {
        cout<<0<<endl;
        return 0;
    }
    if(cnt <= r) ans += (r-cnt)/lcm+1;
    if(cnt < l) ans -= (l-cnt-1)/lcm+1;
    cout<<ans<<endl;
    return 0;
}
*/