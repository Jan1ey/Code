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

struct Edge {
	Edge(int a, int b, int c, int d){
		u = a, v = b, w = c, id = d;
	}
	int u, v, w, id;
};
int n, m;
vector<Edge> edges[maxn], E;
int color[maxn], ord[maxn];
vi order, ans;
bool f = true;

void dfs(int u, int x, int save) {
	if(!f) return;
	color[u] = 1;
	for(auto it : edges[u]) {
		//cout<<it.u<<" "<<it.v<<" "<<it.w<<" "<<it.id<<endl;
		if(it.w <= x) {
			if(save) E.pb(it);
			continue;
		}
		if(color[it.v] == 1) {
			f = false;
			return;
		}
		else if(color[it.v] == 0) dfs(it.v, x, save);
	}
	color[u] = 2;
	if(save) order.pb(u);
}

bool solve(int x, int save = 0) {
	memset(color, 0, sizeof(color));
	f = true;
	rep(i, 1, n) {
		if(!color[i]) dfs(i, x, save);
		if(!f) return false;
	}
	return true;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m;
	rep(i, 1, m){
		int u, v, w;
		cin>>u>>v>>w;
		edges[u].emp(u, v, w, i);
	}
	int l = -1, r = 1e9;
	while(r-l>1) {

		int mid = (l+r)/2;
		if(solve(mid)) r = mid;
		else l = mid;
	}
	cout<<r<<" "; solve(r, 1);
	reverse(order.begin(), order.end());
	for(int i = 0; i < (int)order.size(); i++) ord[order[i]] = i;
	for(auto it : E) {
		if(ord[it.u] > ord[it.v]) ans.pb(it.id);
	}
	sort(ans.begin(), ans.end());
	cout<<(int)ans.size()<<endl;
	for(auto it : ans) cout<<it<<" ";
	puts("");
	return 0;
}
