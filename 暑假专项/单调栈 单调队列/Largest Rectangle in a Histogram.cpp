#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdio>

using namespace std;
const int maxn = 100005;

int a[maxn];
int R[maxn], L[maxn];
stack<pair<int, int> > l, r;

int main()
{
    int n;
    while(~scanf("%d", &n)){
        if(!n) break;
        while(!l.empty()) l.pop();
        while(!r.empty()) r.pop();
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        l.push(make_pair(-1, 0)); r.push(make_pair(-1, n+1));
        for(int i = 1; i <= n; ++i)
        {
            while(l.top().first >= a[i]) l.pop();
            L[i] = l.top().second;
            l.push(make_pair(a[i], i));
        }
        for(int i = n; i >= 1; --i)
        {
            while(r.top().first >= a[i]) r.pop();
            R[i] = r.top().second;
            r.push(make_pair(a[i], i));
        }
        long long ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            ans = max(ans, 1ll*a[i]*(R[i]-L[i]-1));
        }
        printf("%lld\n", ans);
    }
    return 0;
}
