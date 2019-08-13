//
// Created by mile on 2019/7/18.
//

#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007
const int maxn = 2005;

long long f[maxn], finv[maxn], inv[maxn], num[maxn];

void init()
{
    inv[1] = 1, f[0] = finv[0] = 1;
    for(int i = 2; i < maxn; i++) inv[i] = (mod-mod/i)*1ll*inv[mod%i]%mod;
    for(int i = 1; i < maxn; i++)
    {
        f[i] = f[i-1]*1ll*i % mod;
        finv[i] = 1ll*finv[i-1]*inv[i] % mod;
        //cout<<f[i]<<endl;
    }
}
int comb(int n, int m)
{
    if(m < 0 || m > n) return 0;
    return f[n]*1ll*finv[n-m]%mod*finv[m]%mod;
}

int main()
{
    int a, b;
    init();
    while(cin>>a>>b && a+b)
    {
        if(a < b)  swap(a, b);
        int x = a*2+1;
        long long ans = 0;
        for(int i = b; i <= b*2; i++)
        {
            ans += comb(x, i);
            ans %= mod;
        }
        cout<<ans-num[(a+b)]<<endl;
    }
    //cout<<comb(2000 , 1000)<<endl;
    return 0;
}