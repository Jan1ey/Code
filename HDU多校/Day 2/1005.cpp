//
// Created by mile on 2019/7/24.
//

#include <bits/stdc++.h>

#define mod 998244353
using namespace std;
typedef long long LL;

const int maxn = 3005;

LL a[maxn], b[maxn], ans [maxn];

LL qpow(LL a, LL b, LL c) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = ans*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    int n;
    LL tmp = qpow(9, mod-2, mod);
    for(int i = 1; i < maxn; i++) {
        a[i] = i*i%mod;
        b[i] = (i*i-1)%mod;
        ans[i] = (1ll*b[i]*tmp%mod)%mod;
    }
    while(~scanf("%d", &n)) {
        cout<<ans[n]<<endl;
    }
    return 0;
}