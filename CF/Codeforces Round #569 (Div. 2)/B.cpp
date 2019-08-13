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
vector<pair<int, int> > x, y, z;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	for(int i = 1; i <= n; i++) {
		cin>>a[i];
		if(a[i] >= 0) a[i] = -a[i]-1;
		x.emp(a[i], i);
	}
	sort(x.begin(), x.end());
	//reverse(x.begin(), x.end());
	int len = x.size();
	bool flag = true;
	if(len%2) {
		for(int i = 0; i < x.size(); i++) {
			if(x[i].first != -1) {
				x[i].first = -x[i].first-1;
				flag = false;
				break;
			}
		}
		if(flag) x[0].first = 0;
	}
	sort(x.begin(), x.end(), cmp);
	for(auto it : x) {
		cout<<it.first<<" ";
	}
	return 0;
}
