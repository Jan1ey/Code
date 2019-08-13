//-----------------------------------------------
//code by mile
//compiled by clion
//no bug
//Always get ACCEPT
//-----------------------------------------------
#include <bits/stdc++.h>

#define ps push
#define fst first
#define scd second
#define mp make_pair
#define pb push_back
#define emp emplace_back
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define rep0(a, b) for(int a = 0; a < b; ++a)
#define rep1(a, b) for(int a = 1; a <= b; ++a)
#define rep(a, b, c) for(int a = b; a <= c; ++a)
#define ropen freopen("C:\\Users\\mile\\OneDrive\\cpp\\in.txt", "r", stdin)
#define wopen freopen("C:\\Users\\mile\\OneDrive\\cpp\\out.txt", "w", stdout)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef pair<int, long long> pil;
typedef priority_queue<int> pri_big_qe;
typedef priority_queue<int, vector<int>, greater<int> > pri_low_qe;
typedef pair<long long, long long> pll;

const int maxn = 100005;

int a[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--) {
        int n, m, k;
        cin>>n>>m>>k;
        for(int i = 1; i <= n; i++) {
            cin>>a[i];
        }
        int t = a[1];
        bool flag = true;
        for(int i = 2; i <= n; i++) {
            if(abs(a[i-1]-a[i]) <= k) {
                int tmp = a[i-1];
                a[i-1] = max(0, a[i]-k);
                m += tmp-a[i-1];
            } else {
                if(a[i] < a[i-1]) {
                    int tmp = a[i-1];
                    a[i-1] = max(0, a[i]-k);
                    m += tmp-a[i-1];
                } else {
                   int tmp = a[i]-k;
                   if(tmp > a[i-1]+m) {
                       flag = false;
                       break;
                   }else {
                       m -= tmp-a[i-1];
                       a[i-1] = tmp;
                   }
                }
            }
        }
        if(flag) puts("YES");
        else puts("NO");
    }

    return 0;
}
