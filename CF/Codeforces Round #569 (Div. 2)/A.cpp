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

int main() {
	int n;
	scanf("%d", &n);
	long long ans = 1;
	for(int i = 1; i <= n; i++) {
		ans += (i-1)*4;
	}
	cout<<ans<<endl;
	return 0;
}
