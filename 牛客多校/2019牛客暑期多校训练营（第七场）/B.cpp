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
#define ropen freopen("C:\\Users\\mile\\OneDrive\\cpp\\in.txt", "r", stdin)
#define wopen freopen("C:\\Users\\mile\\OneDrive\\cpp\\out.txt", "w", stdout)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef pair<int, long long> pil;
typedef priority_queue<int> pri_qe;
typedef pair<long long, long long> pll;

const int maxn = 100005;

int a[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		for(int i = 1; i <= n+1; i++) cin>>a[i];
		if(n >= 3) printf("NO");
		else {
			if(n == 2) {
				if(a[2]*a[2]-4*a[1]*a[3] >= 0) {
					printf("NO");
				} else printf("YES");
 			} else if( n == 1){
				if(a[1] > 0) printf("YES");
				else printf("NO");
			} else if(n == 0) {
				if(a[1] != 0) printf("NO");
				else printf("YES");
			}
		}
		puts("");
	}

	return 0;
}
