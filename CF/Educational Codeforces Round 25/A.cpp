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

const int maxn = 100005;

char a[maxn];

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int n;
	scanf("%d", &n);
	scanf("%s", a+1);
	int tmp = 1, cnt0 = 0;
	for(int i = 2; i <= n; i++) {
		if(a[i] == '0' && a[i-1] == '1') {
			printf("%d", tmp);
			tmp = 0;
		} else if(a[i] == '0' && a[i-1] == '0') {
			cnt0++;
		} else if(a[i] == '1' && a[i-1] == '0') {
			for(int j = 1; j <= cnt0; j++) printf("%d", 0);
			cnt0 = 0;
			tmp++;
		}
		else tmp += a[i]-'0';
	}
	if(tmp > 0) printf("%d", tmp);
	int t = n;
	while(a[t] != '1') {
		printf("%d",0);
		t--;
	}
	return 0;
}
