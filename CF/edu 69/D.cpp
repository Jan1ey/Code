//-----------------------------------------------
//code by mile
//compiled by clion
//no bug
//Always get ACCEPT
//-----------------------------------------------

#include <bits/stdc++.h>

#define pb push_back
#define emp emplace_back
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 300005;

int n, m, k;
int a[maxn];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    long long ans = 0;
    for(int i = 0; i < m; i++) {
        long long tmp = 0, mn = 0;
        for(int j = i; j < n; j++) {
            if(j%m == i) {
                mn = min(mn, tmp);
                tmp += a[j]-k;
            } else tmp += a[j];
            ans = max(ans, tmp-mn);
        }
    }
    cout<<ans<<endl;
    return 0;
}