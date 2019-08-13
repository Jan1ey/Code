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

const int maxn = 2005;

string s[maxn];
vector<vector<int> > mark(maxn, vector<int>(maxn));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n, k;
	cin>>n>>k;
	rep0(i, n) cin>>s[i];

	int ans = 0;
	rep0(i, n) {
		int lmin = -1, rmax = -1;
		rep0(j, s[i].size()) {
			if(s[i][j] == 'B') {
				if(lmin == -1) lmin = j;
				rmax = j;
			}
		}
		if(lmin == -1 && rmax == -1) {ans++; continue;}
		int lrow = i-k+1, row = i;
		int lc = rmax-k+1, rc = lmin;
		lrow = max(0, lrow); lc = max(0, lc);
		if(lc <= rc && lrow <= row) {
			mark[lrow][lc]++;
			mark[lrow][rc+1]--;
			mark[row+1][lc]--;
			mark[row+1][rc+1]++;
		}
	}
	rep0(i, n) {
		int lmin = -1, rmax = -1;
		rep0(j, n) {
			if(s[j][i] == 'B') {
				if(lmin == -1) lmin = j;
				rmax = j;
			}
		}
		if(lmin == -1 && rmax == -1) {ans++; continue;}
		int lrow = rmax-k+1, row = lmin;
		int lc = i-k+1, rc = i;
		lrow = max(0, lrow), lc = max(0, lc);
		if(lc <= rc && lrow <= row) {
			mark[lrow][lc]++;
			mark[lrow][rc+1]--;
			mark[row+1][lc]--;
			mark[row+1][rc+1]++;
		}
	}
	rep0(i, n) {
		rep0(j, n) {
			mark[i][j+1] += mark[i][j];
		}
	}
	rep0(i, n) {
		rep0(j, n) {
			mark[i+1][j] += mark[i][j];
		}
	}
	int tmp = 0;
	rep0(i, n) {
		rep0(j, n) {
			//cout<<mark[i][j]<<" ";
			tmp = max(tmp, ans+mark[i][j]);
		}
		//cout<<endl;
	}
	//cout<<endl;
	cout<<tmp<<endl;
    return 0;
}
