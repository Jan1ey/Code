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
const int maxn = 200005;

int n;
int num[maxn];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}
	for(int i = 2; i <= n; i++) {
		if(num[i] < num[i-1] && num[i] < num[i+1]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
	return 0;
}
