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

const int maxn = 100005;

string x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>x;

	int len = x.size();
	int st = -1;
	for(int i = 0; i < len; ++i) {
		if(x[i] == '[') {
			st = i;
			break;
		}
	}
	int ed = -1;
	for(int i = len; i > st && i >= 0; --i){
		if(x[i] == ']') {
			ed = i;
			break;
		}
	}

	if(ed == -1 || st == -1) {
		cout<<-1<<endl;
		return 0;
	}
	else {
		int a = -1, b = -1;
		for(int i = st+1; i <= ed; ++i) {
			if(x[i] == ':') {
				a = i;
				break;
			}
		}
		for(int i = ed-1; i > a; i--) {
			if(x[i] == ':') {
				b = i;
				break;
			}
		}
		if(a == -1 || b == -1 || a == b) {
			cout<<-1<<endl;
			return 0;
		}
		else {
			int ans = 4;
			for(int i = a+1; i < b; i++) {
				if(x[i] == '|') ans++;
			}
			cout<<ans<<endl;
		}
	}

	return 0;
}
