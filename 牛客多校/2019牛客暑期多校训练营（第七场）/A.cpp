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
#define ropen freopen("C:\\Users\\mile\\OneDrive\\cpp\\in.txt", "r", stdin)
#define wopen freopen("C:\\Users\\mile\\OneDrive\\cpp\\out.txt", "w", stdout)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef pair<int, long long> pil;
typedef priority_queue<int> pri_qe;
typedef pair<long long, long long> pll;

const int maxn = 1005;

string s[maxn];
int c0[maxn], c1[maxn];
string ans[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;
	string x;
	while(t--) {
		memset(c0, 0, sizeof(c0));
		memset(c1, 0, sizeof(c1));
		cin>>x;
		int len = x.size();
		int cnt = 1;
		s[1] = "";
		int j = 0;
		while(x[j] == '0' && j < len) s[cnt] += '0', c0[cnt]++, j++;
		for(; j < len;) {
			if(x[j] == '0') {
				cnt++;
				s[cnt] = "";
				while(x[j] == '0' && j < len) s[cnt] += '0', c0[cnt]++, j++;
			} else {
				while(x[j] == '1' && j < len) s[cnt] += '1', c1[cnt]++, j++;
			}
		}
		bool flag = true;
		int num = 1;
		while(flag) {
			flag = false;
			num = 1;
			string tmp = s[1];
			for (int i = 2; i <= cnt; i++) {
				string cmp1 = s[i] + tmp;
				string cmp2 = tmp + s[i];
				if (cmp1 < cmp2) {
					ans[num++] = tmp;
					tmp = s[i];
				} else {
					flag = true;
					tmp += s[i];
				}
			}
			ans[num] = tmp;
			cnt = num;
			for(int i = 1; i <= num; i++) {
				s[i] = ans[i];
			}
		}
		for(int i = 1; i < cnt; i++) {
			cout<<s[i]<<" ";
		}
		cout<<s[cnt]<<endl;
	}

	return 0;
}
