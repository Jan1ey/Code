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
#define INT_INF 2147483647
#define LL_INF 9223372036854775807
#define PI acos(-1)
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

void close(){   ios::sync_with_stdio(false);cin.tie(0); }

/*********************Start Here**********************************/

const ll mod = 1e9+7;
const int maxn = 200005;

vi G[maxn], a(maxn);
vector<pii> dp[maxn];

int ans = 0;

void cal(int v, int p = -1) {
	vector<pii> chd;
	for(auto it : G[v]) {
		if(it != p) {
			cal(it, v);
			for(auto its : dp[it]) {
				chd.pb(its);
			}
		}
	}
	sort(chd.begin(), chd.end());
	rep(i, 0, (int)chd.size()-1) {
		int j = i-1;
		int mx1 = 0, mx2 = 0;
		while(j+1 < chd.size() && chd[j+1].fst == chd[i].fst) {
			++j;
			if(chd[j].scd >= mx1) {
				mx2 = mx1, mx1 = chd[j].scd;
			} else if(chd[j].scd > mx2) {
				mx2 = chd[j].scd;
			}
		}
		if(a[v] % chd[i].fst == 0) {
			ans = max(ans, mx2+mx1+1);
			dp[v].emp(chd[i].fst, mx1+1);
			while(a[v] % chd[i].fst == 0) {
				a[v] /= chd[i].fst;
			}
		}
		else {
			ans = max(ans, mx1);
		}
		i = j;
	}

	for(int i = 2; i * i <= a[v]; ++i) {
		if(a[v] % i == 0) {
			ans = max(ans, 1);
			dp[v].emp(i, 1);
			while(a[v] % i == 0) {
				a[v] /= i;
			}
		}
	}

	if(a[v] > 1) {
		dp[v].emp(a[v], 1);
		ans = max(ans, 1);
	}
}

void solve() {
	cal(1);
	cout<<ans<<endl;
}

int main() {

	close();

	int n;
	cin>>n;
	rep(i, 1, n) cin>>a[i];
	rep(i, 1, n-1) {
		int u, v;
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}

	solve();

	return 0;
}
