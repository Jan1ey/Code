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

const int maxn = 17;
const int maxm = 10005;

int dp[1<<maxn][maxn];

int num[maxn][maxn], a[maxn][maxm];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin>>n>>m;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin>>a[i][j];
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			num[i][j] = INF;
			for(int k = 0; k < m; k++) {
				num[i][j] = min(num[i][j], abs(a[i][k]-a[j][k]));
			}
			num[j][i] = num[i][j];
		}
	}

	int ans = 0;
	for(int ed = 0; ed < n; ed++) {
		for(int i = 0; i < 1<<n; i++)
			memset(dp[i], 0, sizeof(dp[i]));
		dp[1<<ed][ed] = INF;
		for(int i = 0; i < 1<<n; i++) {
			for (int j = 0; j < n; j++) {
				if (dp[i][j]) {
					for(int k = 0; k < n; k++) {
						if(!(i & 1<<k)) {
							dp[i | 1<<k][k] = max(dp[i | 1<<k][k], min(dp[i][j], num[j][k]));
						}
					}
				}
			}
		}
		for(int i = 0; i < n; i++) {
			int k = dp[(1<<n)-1][i];
			for(int j = 0; j+1 < m; j++) {
				k = min(k, abs(a[i][j]-a[ed][j+1]));
			}
			ans = max(ans, k);
		}
	}
	cout<<ans<<endl;

	return 0;
}
