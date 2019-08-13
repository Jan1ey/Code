//
// Created by mile on 2019/7/29.
//
//威尔逊定理:(p-1)!(mod p) = -1(mod p) + __int128

#include <bits/stdc++.h>

#define ll __int128
using namespace std;

bool Isprime(long long x) {
    long long ans = 1;
    for(int i = 2; i <= sqrt(x); i++) {
        if(x % i == 0) return false;
    }
    return true;
}

ll qpow(ll a, ll b, ll c) {
    ll ans = 1;
    while(b) {
        if(b&1) ans = ans*a%c;
        a = a*a%c;
        b >>= 1;
    }
    return ans;
}



int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        long long n;
        scanf("%lld", &n);
        ll ans = 1, p = n;n -= 2;
        while(!Isprime(n))  {
            ans = ans * qpow(n, p-2, p) % p;
            ans %= p;
            n--;
        }
        long long x = qpow(p-1, p-2, p) % p;
        cout<<x<<endl;
    }
    return 0;
}