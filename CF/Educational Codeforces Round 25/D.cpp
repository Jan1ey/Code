//-----------------------------------------------
//code by mile
//compiled by clion
//no bug
//Always get ACCEPT
//-----------------------------------------------
#include <bits/stdc++.h>

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
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<int, long long> pil;
typedef vector<int> vi;
typedef vector<long long> vll;

const int maxn = 1000005;

int num;
char a[maxn], b[maxn];
int visa[333], visb[333];

bool check(int x) {
	int cnt = 0;
	for(int i = 0; i <= 28; i++) {
		if(visb[i]) {
			cnt += max(0, x*visb[i]-visa[i]);
		}
	}
	return cnt<=num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	scanf("%s%s", a+1, b+1);
	int lena = strlen(a+1), lenb = strlen(b+1);
	for(int i = 1; i <= lena; i++) {
		if(a[i] == '?') num++;
		visa[a[i]-'a']++;
	}
	for(int i = 1; i <= lenb; i++) {
		visb[b[i]-'a']++;
	}
	int ans = 0;
	int l = 0, r = lena/lenb;
	while(l <= r) {
		int mid = (l+r)>>1;
		if(check(mid)) {
			l = mid+1, ans = mid;
		} else r = mid-1;
	}
	if(check(l)) ans = max(ans, l);
	for(int i = 1; i <= lena; i++) {
		if(a[i] == '?') {
			for(int j = 0; j <= 28; j++) {
				if(visb[j]*ans > visa[j]) {
					a[i] = 'a'+j;
					visa[j]++;
					break;
				}
			}
		}
	}
	for(int i = 1; i <= lena; i++) {
		if(a[i] == '?') a[i] = 'l';
	}
	printf("%s", a+1);
	return 0;
}
