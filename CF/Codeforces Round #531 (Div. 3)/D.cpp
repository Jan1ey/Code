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

string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	cin>>s;

	int a, b, c;
	c = b = a = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '0') a++;
		else if(s[i] == '1') b++;
		else c++;
	}

	if(a == b && b == c) {
		cout<<s<<endl;
		return 0;
	}
	else {
		int x = n/3;
		int cnt = n-1;
        while(c < x && cnt >= 0) {
            if(s[cnt] == '1' && b > x) s[cnt] = '2', c++, b--;
            cnt--;
        }
        cnt = n-1;
        while(c < x && cnt >= 0) {
            if(s[cnt] == '0' && a > x) s[cnt] = '2', c++, a--;
            cnt--;
        }
        cnt = 0;
        while(a < x && cnt < n) {
            if(s[cnt] == '2' && c > x) s[cnt] = '0', a++, c--;
            if(s[cnt] == '1' && b > x) s[cnt] = '0', a++, b--;
            cnt++;
        }
		cnt = 0;
		while(b < x && cnt < n) {
			if(s[cnt] == '2' && c > x) s[cnt] = '1', b++, c--;
			cnt++;
		}
        cnt = n-1;
        while(b < x && cnt >= 0) {
            if(s[cnt] == '0' && a > x) s[cnt] = '1', b++, a--;
            cnt--;
        }
	}

	cout<<s<<endl;

	return 0;
}
