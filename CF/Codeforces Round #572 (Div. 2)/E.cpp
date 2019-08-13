#include <bits/stdc++.h>

using namespace std;

map<long long, long long> mp;

int main()
{
    int n, p, k;
    scanf("%d%d%d", &n, &p, &k);
    long long ans = 0;
    for(int i = 1; i <= n; i++)
    {
        long long m;
        scanf("%lld", &m);
        long long tmp =((m*m)%p*m%p*m%p-k*m%p+p)%p;
        if(!mp[tmp]) mp[tmp] = 1;
        else ans += mp[tmp], mp[tmp]++;
    }
    cout<<ans<<endl;
    return 0;
}
