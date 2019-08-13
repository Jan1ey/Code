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

ll k, m;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}

bool check(ll x) {
	int cnt = 0;
	ll i = 1;

	while(true) {
		if(gcd(x, i) == 1) cnt++;
		if(cnt == m) {
			//cout<<(i^x)<<" "<<k<<endl;
			if((i^x) == k) return true;
			else return false;
		}
		i++;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--) {
		cin>>k>>m;
		bool flag = false;
		for(ll i = max(k-500, 1ll); i <= k+500; i++) {
			if(check(i)) {
				printf("%lld\n", i);
				flag = true;
				break;
			}
		}
		if(!flag) printf("-1\n");
	}
	return 0;
}
