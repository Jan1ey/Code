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
const int maxn = 300005;

int n, m, k;
int a[maxn];
vector<long long> ans;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	long long tmp = 0;
	for(int i = m, len = 0; i+len <= n; len++) {
		long double y = (len+1)*1.0/(m*1.0);
		long long x = k*ceil(y);
		tmp += a[i+len];
		//cout<<tmp-x<<endl;
		ans.push_back(tmp-x);
	}
	sort(ans.begin(), ans.end());
	cout<<max(ans.back(), 0ll)<<endl;
	return 0;
}
