//-----------------------------------------------
//code by mile
//compiled by clion
//no bug
//Always get ACCEPT
//-----------------------------------------------

#include <bits/stdc++.h>


#define epb emplace_back
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 200005;

int b[maxn];
vector<int> p[maxn];


int main() {
	int n, m, k, q; int tp = 0;
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for(int i = 1; i <= k; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		p[x].push_back(y);
		tp = max(x, tp);
	}
	for(int i = 0; i < q; i++) scanf("%d", &b[i]);
	sort(b, b+q);

	vector<pair<int, long long> > dp0;
	int prv = 1, s = 1;
	if(p[1].empty()) {
		for(int i = 0; i< q; i++) dp0.epb(b[i], b[i]-1);
		s = 2;
	} else {
		dp0 = {make_pair(1, 0)};
	}
	for(int i = s; i <= n; i++) {
		if(p[i].empty()) continue;
		sort(p[i].begin(), p[i].end());
		int dist = i-prv;
		int lb = p[i].front(), rb = p[i].back();
		long long ld = 1e18, rd = 1e18;
		for(int j = 0; j < (int)dp0.size(); j++) {
			long long ldp = dp0[j].second+abs(dp0[j].first-rb)+abs(rb-lb)+dist;
			long long rdp = dp0[j].second+abs(dp0[j].first-lb)+abs(rb-lb)+dist;
			ld = min(ld, ldp);
			rd = min(rd, rdp);
		}
		if(i == tp) {
			printf("%lld\n", min(ld, rd));
			return 0;
		}
		int pos = lower_bound(b, b+q, lb)-b;
		vector<pair<int, long long> > dp1;
		if(pos != q) dp1.epb(b[pos], ld+abs(b[pos]-lb));
		if(pos > 0) dp1.epb(b[pos-1], ld+abs(b[pos-1]-lb));
		pos = lower_bound(b, b+q, rb)-b;
		if(pos != q) dp1.epb(b[pos], rd+abs(b[pos]-rb));
		if(pos > 0) dp1.epb(b[pos-1], rd+abs(b[pos-1]-rb));
		dp0 = dp1;
		prv = i;
	}
	return 0;
}