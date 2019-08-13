
//二分
/*
#include <bits/stdc++.h>

using namespace std;

long long num[200005];
int n, k;

int solve(long long x) {
    long long tmp = k;
    for(int i = n/2+1; i <= n; i++) {
        if(num[i] < x) tmp -= (x-num[i]);
    }
    if(tmp < 0) return false;
    return true;
}

int main()
{
    scanf("%d%d",&n, &k);
    for(int i = 1; i <= n; i++) scanf("%I64d", &num[i]);
    sort(num+1, num+n+1);
    long long l = num[n/2+1], r = num[n]+k;
    long long ans = 0;
    while(l <= r) {
        long long mid = (l+r)>>1;
        //cout<<mid<<endl;
        if(solve(mid)) {
            l = mid+1;
            ans = mid;
        } else r = mid-1;
    }
    if(solve(l)) ans = max(ans, l);
    printf("%I64d\n", ans);
    return 0;
}
*/
//O(n)

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

long long num[200005];

int main()
{
    long long n, k;
    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>num[i];
    sort(num, num+n);
    ll cnt = 1, ans = num[n/2];
    for(int i = n/2; i < n; i++) {
        if(i+1 == n) ans += k/cnt;
        else {
            ll x = num[i+1]-num[i];
            if(k >= x*cnt) {
                k -= x*cnt, ans = num[i+1], cnt++;
            } else {
                ans += k/cnt;
                break;
            }
        }
    }
    cout<<ans<<endl;
}