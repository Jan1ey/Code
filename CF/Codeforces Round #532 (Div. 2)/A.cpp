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
#define rep(a, b, c) for(int a = b; a <= c; ++a)
#define ropen freopen("C:\\Users\\mile\\OneDrive\\cpp\\in.txt", "r", stdin)
#define wopen freopen("C:\\Users\\mile\\OneDrive\\cpp\\out.txt", "w", stdout)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef pair<int, long long> pil;
typedef priority_queue<int> pri_big_qe;
typedef priority_queue<int, vector<int>, greater<int> > pri_low_qe;
typedef pair<long long, long long> pll;

const int maxn = 100005;

int s[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin>>n>>k;
	int a, b; a = b = 0;
	rep(i, 1, n) cin>>s[i], s[i] == 1 ? ++a : ++b;
	int mx = 0;
	//cout<<a<<" "<<b<<endl;
	rep(i, 1, k) {
		int ta = a, tb = b;
		for(int j = i; j <= n; j += k) {
			s[j] == 1 ? --ta : --tb;
		}
		//cout<<i<<" "<<ta<<" "<<tb<<endl;
		mx = max(mx, abs(ta-tb));
	}
	cout<<mx<<endl;
	return 0;
}
