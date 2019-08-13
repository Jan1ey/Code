//
// Created by mile on 2019/7/18.
//

#include <bits/stdc++.h>

#define mod 998244353
using namespace std;
const int maxn = 100005;

long long num[maxn];

int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>num[i];
    int len = 0, s = num[1];
    while(s) len++, s /= 10;
    long long pow[15]; pow[1] = 1;
    //cout<<len<<endl;
    for(int i = 2; i <= len; i++)  pow[i] = pow[i-1]*10;
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        //cout<<num[i]<<" "<<pow[len]<<endl;
        long long m = 1ll*num[i]/pow[len];
        num[i] %= pow[len];
        //cout<<num[i]<<" "<<pow[len]<<endl;
        for (int j = len-1; j >= 1; j--) {
            m *= 100, m += (num[i] / pow[j]);
            num[i] %= pow[j];
        }
        //cout<<m<<endl;
        ans = ans % mod + ((m % mod) * n) %mod;
        ans %= mod;
        m %= mod;
        m *= 10;
        m %= mod;
        //cout<<m<<endl;
        ans = ans % mod + ((m % mod) * n) %mod;
        ans %= mod;
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}