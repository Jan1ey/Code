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

int n, k;
vector<int> num(maxn), sub;

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &num[i]);
	for(int i = 2; i <= n; i++) {
		int tmp = num[i] - num[i-1];
		sub.push_back(tmp);
	}
	sort(sub.begin(), sub.end());
	for(int i = sub.size()-1, j = k; j > 1 && i >= 0; i--,j--) {
		sub[i] = 0;
	}
	long long ans = 0;
	for(int i = 0; i < sub.size(); i++) {
		ans += sub[i];
	}
	printf("%lld\n", ans);
	return 0;
}
