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

struct node {
	int l, r, id, vis;
	bool operator < (const node& a)const {
		return l < a.l;
	}
};

bool cmp (node a, node b) {
	return a.id < b.id;
}

node a[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;

		for(int i = 1; i <= n; i++)  {
			cin>>a[i].l>>a[i].r;
			a[i].id = i;
		}

		sort(a+1, a+n+1);

		int r = a[1].r;
		bool flag = false;
		for(int i = 1; i <= n; i++) {
			if(a[i].l > r) {
				for(int j = 1; j <= n; j++) {
					a[j].vis = a[j].l > r ? 2 : 1;
				}
				flag = true;
				break;
			}
			r = max(r, a[i].r);
		}

		if(!flag) cout<<-1<<endl;
		else {
			sort(a+1, a+n+1, cmp);
			for(int i = 1; i <= n; i++) {
				cout<<a[i].vis<<" ";
			}
			cout<<endl;
		}

	}

	return 0;
}
