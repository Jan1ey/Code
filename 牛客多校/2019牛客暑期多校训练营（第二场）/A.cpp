//
// Created by mile on 2019/7/20.
//

#include <bits/stdc++.h>

#define mod 1000000007
using namespace std;
typedef long long ll;

ll _pow(ll a, ll b)
{
    int ans = 1;
    while(b)
    {
        if(b&1) ans = (ans*a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    ll ans = 1;
    while(t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        if(n == 1) cout<<ans<<endl;
        else {
            if(m == 0) ans = 0;
            else {
                ans = ans * _pow(n-1, mod-2) % mod;
            }
            cout<<ans<<endl;
        }

    }
    return 0;
}