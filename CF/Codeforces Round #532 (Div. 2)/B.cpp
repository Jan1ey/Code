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

set<int> s;
vi v;
int num[maxn], vis[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin>>n>>m;
	rep(i, 1, m) cin>>num[i];
	rep(i, 1, m) {
		s.insert(num[i]);
		vis[num[i]]++;
		if(s.size() >= n) {
			cout<<1;
			v.clear();
			for(auto it : s) v.pb(it);
			for(auto it : v) {
				if(--vis[it] == 0) s.erase(it);
			}
		} else cout<<0;
	}

	return 0;
}
