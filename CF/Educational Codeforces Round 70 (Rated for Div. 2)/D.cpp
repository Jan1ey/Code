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
#define rep0(a, b) for(int a = 0; a < b; ++a)
#define rep1(a, b) for(int a = 1; a <= b; ++a)
#define ropen freopen("C:\\Users\\mile\\OneDrive\\cpp\\in.txt", "r", stdin)
#define wopen freopen("C:\\Users\\mile\\OneDrive\\cpp\\out.txt", "w", stdout)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef pair<int, long long> pil;
typedef priority_queue<int> pri_qe;
typedef pair<long long, long long> pll;

const int maxn = 100005;

ll a[maxn];
vi num;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    a[2] = 1;
    for(int i = 3; i < maxn; i++) {
        a[i] = a[i-1]+(i-1);
    }

    int t;
    cin>>t;
    while(t--) {
        num.clear();
        int n;
        cin>>n;
        for(int i = 2; i < 99998; i++) {
            if(a[i] > n) {
                n -= a[i-1];
                num.pb(i-1);
                if(n == 0) break;
                i = 1;
            }
        }
        for(int i = 0; i < num.size(); i++) {
            //cout<<num[i]<<endl;
            cout<<1;
            if(i != num.size()-1) {
                //cout<<a[num[i]-num[i+1]]<<endl;
                for(int j = 1; j <= num[i]-num[i+1]; j++) cout<<3;
            } else {
                rep1(j,num[i]) cout<<3;
            }
        }
        cout<<7;
        cout<<endl;
    }


    return 0;
}
