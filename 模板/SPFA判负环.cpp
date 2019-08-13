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

struct Edge {
	Edge(int a, int b, int c) {
		from = a; to = b; dist = c;
	}
	int from, to, dist;
};

struct BellmanFord {
	int n, m;
	vector<Edge> edges;
	vi G[maxn];
	bool inq[maxn];
	int d[maxn];
	int p[maxn];
	int cnt[maxn];

	void init(int n) {
		this->n = n;
		for(int i = 0; i < n; i++) G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, int dist) {
		edges.pb((Edge){from, to, dist});
		m = edges.size();
		G[from].pb(m-1);
	}

	bool negativeCycle() {
		queue<int> Q;
		memset(inq, 0, sizeof(inq));
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < n; i++) {
			d[i] = 0;
			inq[i] = true;
			Q.ps(i);
		}

		while(!Q.empty()) {
			int u = Q.front(); Q.pop();
			inq[u] = false;
			for(int i = 0; i < G[u].size(); ++i) {
				Edge& e = edges[G[u][i]];
				if(d[e.to] > d[u]+e.dist) {
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];
					if(!inq[e.to]) {
						Q.ps(e.to);
						inq[e.to] = true;
						if(++cnt[e.to] > n) return true;
					}
				}
			}
		}
		return false;
	}
};

BellmanFord a;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		a.init(n);
		rep(i, 1, m) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			u--, v--;
			a.AddEdge(u, v, w);
			if(w >= 0) a.AddEdge(v, u, w);
		}
		if(a.G[0].empty()) {
			puts("N0");
			continue;
		}
		if(a.negativeCycle()) {
			puts("YE5");
		} else puts("N0");
	}

	return 0;
}
