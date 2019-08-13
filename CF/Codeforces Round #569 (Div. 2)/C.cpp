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
const int maxn = 100005;

int a[maxn];
deque<int> dq;
vector<pair<int, int> > pi, res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q, mx = 0;
	cin>>n>>q;
	for(int i = 1; i <= n; i++) cin>>a[i], dq.push_back(a[i]), mx = max(mx, a[i]);
	int num = 0;
	while(dq.front() != mx) {
		int x = dq.front(); dq.pop_front();
		int y = dq.front(); dq.pop_front();
		if(x > y) dq.push_front(x), dq.push_back(y);
		else dq.push_front(y), dq.push_back(x);
		pi.emp(x, y);
		num++;
	}
	dq.pop_front();
	while(!dq.empty()) {
		int tmp = dq.front(); dq.pop_front();
		res.emp(mx, tmp);
	}
	int len = pi.size(), loop = res.size();
	while(q--) {
		long long x;
		cin>>x;
		if(x <= len) {
			printf("%d %d\n", pi[x-1].first, pi[x-1].second);
		} else {
			x -= len+1;
			printf("%d %d\n", res[x%loop].first, res[x%loop].second);
		}
	}
	return 0;
}
