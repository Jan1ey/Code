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

int n;
int num[maxn];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
		sort(num+1, num+n+1);
		int a = num[n-1], b = num[n];
		if(n == 3 && min(a, b) > 1) printf("%d\n", 1);
		else if(n == 2) printf("%d\n", 0);
		else if(a == 1 || b == 1) printf("%d\n", 0);
		else printf("%d\n", min(min(a, b)-1, n-2));
	}
	return 0;
}
