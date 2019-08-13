#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;



int main()
{
    long long n, m, tmp;
    scanf("%I64d%I64d", &n, &m);
    long long ans = (n%mod)*(m%mod)%mod;
    long long las = m+1;
    m = min(m, n);
    tmp = 0;
    for(long long i = 1; i <= (long long)sqrt(n*1.0); i++)
    {
        long long l = n/(i+1)+1, r = n/i;
        r = min(r, m);
        if(l > r) continue;
        las = min(las, l);
        long long s1 = l+r, s2 = r-l+1;
        if(s1%2 == 0) s1 /= 2;
        else s2 /= 2;
        s1 %= mod, s2 %= mod;
        s1 = (s1 * s2) % mod;
        s1 = (s1 * i) % mod;
        tmp = (tmp + s1) % mod;
    }
    ans = (ans - tmp + mod) % mod;
    for(int i = 1; i < las; i++)
    {
        tmp = n/i%mod*i%mod;
        ans = (ans-tmp+mod)%mod;
    }
    printf("%I64d\n", ans);
    return 0;
}
