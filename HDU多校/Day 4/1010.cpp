//
// Created by mile on 2019/7/31.
//

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int pri[10007], vis[10007];
ll num = 0;

int main()
{
    for(int i = 2; i <= 10005; i++) {
        if(!vis[i]) {
            pri[++num] = i;
            for (int j = i + i; j <= 10005; j += i) {
                vis[j] = 1;
            }
        }
    }
    int t;
    scanf("%d", &t);
    while(t--) {
        ll n;
        scanf("%lld", &n);
        ll ans = 0x3f3f3f3f, cnt = 0;
        for(ll i = 1; i <= num && 1ll*pri[i]*pri[i] <= n; i++) {
            if(n % pri[i] == 0) {
                ll cnt = 0;
                while(n % pri[i] == 0)  n /= pri[i], cnt++;
                ans = min(ans, cnt);
            }
        }
        if(n == 1) {
            printf("%lld\n", ans);
            continue;
        }
        ll x = powl(n, 0.25)+0.5;
        if(x*x*x*x == n) {
            ans = min(ans, 4ll);
            printf("%lld\n", ans);
            continue;
        }
        x = powl(n, 1.0/3.0)+0.5;
        if(x*x*x == n) {
            ans = min(ans, 3ll);
            printf("%lld\n", ans);
            continue;
        }
        x = powl(n, 0.5)+0.5;
        if(x*x == n) {
            ans = min(ans, 2ll);
            printf("%lld\n", ans);
            continue;
        }
        ans = min(ans, 1ll);
        printf("%lld\n", ans);
    }
    return 0;
}