//-----------------------------------------------
//code by mile
//compiled by clion
//no bug
//Always get ACCEPT
//Template：Prefix function
//solution for：子串s[0..i]中既是后缀同时也是前缀的最长真前缀的长度
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}
