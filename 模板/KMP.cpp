//-----------------------------------------------
//code by mile
//compiled by clion
//no bug
//Always get ACCEPT
//Template：KMP
//solution for：给定一个文本串s和一个字符串t，找到并展示t在s中的所有出现位置
//-----------------------------------------------
#include <bits/stdc++.h>

#define ps push
#define fst first
#define scd second
#define mp make_pair
#define pb push_back
#define emp emplace_back
#define INF 0x3f3f3f3f
#define Pi acos(-1)
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

vi prefix_function(string s) {          //前缀函数
	int n = (int)s.size();
	vi pi(n);
	for(int i = 1; i < n; i++) {
		int j = pi[i-1];
		while(j > 0 && s[i] != s[j]) j = pi[j-1];
		if(s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

vi KMP(string s, string t) {            //KMP匹配
	vi nxt = prefix_function(t);

	int slen = s.size();
	int tlen = t.size();
	int k = 0;
	vi ans;
	for(int i = 0; i < slen; ++i) {
		while(k > 0 && s[i] != t[k]) k = nxt[k-1];
		if(s[i] == t[k]) k++;
		if(k == tlen) {
			ans.pb(i-tlen+2);
		}
	}
	return ans;
}

vi ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, t;//s为文本串，t为模式串
	cin>>s>>t;

	ans = KMP(s, t);

	for(auto it : ans) cout << it << endl;

	return 0;
}
