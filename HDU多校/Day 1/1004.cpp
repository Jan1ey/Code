//
// Created by mile on 2019/7/22.
//
/*
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 100005;

ll l[maxn], s[maxn], v[maxn], len[maxn];

int main()
{
    int n;
    while(~scanf("%d", &n)) {
        long double ans = 0.0;
        for(int i = 0; i <= n; ++i) scanf("%lld", &l[i]);
        for(int i = 0; i <= n; ++i) scanf("%lld", &s[i]);
        for(int i = 0; i <= n; ++i) scanf("%lld", &v[i]);
        len[0] = l[0];
        for(int i = 1; i <= n; ++i) len[i] = len[i-1]+l[i];
        for(int i = n; i >= 0; --i)
        {
            long double tmp;
            tmp = (long double)(s[i]+len[i]-l[0])*1.0;
            //cout<<fixed<<showpoint<<setprecision(10)<<tmp<<endl;
            tmp /= (long double) v[i];
            //cout<<fixed<<showpoint<<setprecision(10)<<tmp<<endl;
            ans = max(tmp, ans);
        }
        cout<<fixed<<showpoint<<setprecision(10)<<ans<<endl;
    }
    return 0;
}
*/