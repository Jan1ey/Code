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

int deg[maxn];
vi edges[maxn], ans(maxn);

int a[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin>>n>>m;
	rep1(i, m) {
		int u, v;
		cin>>u>>v;
		edges[v].pb(u);
		++deg[u];
	}
	int cnt = n;
	pri_qe q;
	rep1(i, n) {
		if(deg[i] == 0) q.ps(i);
	}
	while(!q.empty()) {
		int u = q.top();
		q.pop();
		ans[u] = cnt--;
		for(auto it : edges[u]) {
			if(--deg[it] == 0) {
				q.ps(it);
			}
		}
	}
	rep1(i, n) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
