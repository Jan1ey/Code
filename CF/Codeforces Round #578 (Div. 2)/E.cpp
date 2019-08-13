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

const int maxn = 100005;

vi get_p(string s) {
	int n = s.size();
	vi p(n);
	int len = 0;
	for(int i = 1; i < n; i++) {
		while(len > 0 && s[len] != s[i]) len = p[len-1];
		len += (s[i] == s[len] ? 1 : 0);
		p[i] = len;
	}
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string ans = "";
	int n;
	cin>>n;
	rep(i, 1, n) {
		string tmp;
		cin>>tmp;
		int lena = ans.size();
		int lent = tmp.size();
		int sta = max(0, lena-lent);
		vi p = get_p(tmp);

		int max_len = 0;
		for(int j = sta; j < lena; ++j) {
			while(max_len>0 && tmp[max_len] != ans[j]) max_len = p[max_len-1];
			if(tmp[max_len] == ans[j]) ++max_len;
		}
		ans += tmp.substr(max_len);
	}
	cout<<ans<<endl;
	return 0;
}
