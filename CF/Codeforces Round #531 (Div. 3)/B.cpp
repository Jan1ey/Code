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
#define pi acos(-1)
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

/*********************Start Here**********************************/

const int maxn = 5005;

int a[maxn], num[maxn];
set<int> S;
set<int> C[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin>>n>>k;
	for(int i = 1; i <= n; ++i) cin>>a[i], num[a[i]]++, S.insert(a[i]);
	if(n < k) {
		cout<<"NO"<<endl;
		return 0;
	}
	int cnt = 1;
	for(auto it : S) {
		if(num[it] > k) {
			cout<<"NO"<<endl;
			return 0;
		}
	}
	for(int i = 1; i <= k; i++) {
		C[a[i]].insert(i);
	}
	for(int i = k+1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			if(C[a[i]].find(j) != C[a[i]].end()) {
			} else {
				C[a[i]].insert(j);
				break;
			}
		}
	}

	cout<<"YES"<<endl;
	for(int i = 1; i <= n; i++) {
		for(auto it : C[a[i]]) {
			cout<<it<<" ";
			C[a[i]].erase(C[a[i]].begin());
			break;
		}
	}

	return 0;
}
