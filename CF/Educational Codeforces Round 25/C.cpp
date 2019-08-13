//-----------------------------------------------
//code by mile
//compiled by clion
//no bug
//Always get ACCEPT
//-----------------------------------------------
#include <bits/stdc++.h>

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
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<int, long long> pil;
typedef vector<int> vi;
typedef vector<long long> vll;

const int maxn = 100005;

ll a[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n>>k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	ll mx = k;
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] > mx*2) {
			while(mx*2 < a[i]) ans++, mx*=2;
			mx = max(mx, a[i]);
		} else mx = max(mx, a[i]);
	}
	cout<<ans<<endl;
	return 0;
}
