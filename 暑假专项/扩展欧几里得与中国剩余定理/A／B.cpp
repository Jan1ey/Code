//
// Created by mile on 2019/7/21.
//
/*
#include <bits/stdc++.h>

using namespace std;
const int mod = 9973;

long long _pow(long long a, long long b)
{
    long long ans = 1;
    while(b) {
        if(b & 1) ans = ans*a%mod;
        a = a*a%mod; b >>= 1;
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        long long n, m;
        cin>>n>>m;
        long long ans = n * _pow(m, mod-2) % mod;
        cout<<ans<<endl;
    }
    return 0;
}
*/