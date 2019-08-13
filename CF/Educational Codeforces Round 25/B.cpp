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

char mps[15][15];

bool check1(int x, int y) {
	int cnt = 0;
	int l = x-1, r = y;
	while(l >= 1 ) {
		if(mps[l][r] == '.' || mps[l][r] == 'O') break;
		if(mps[l--][r] == 'X') cnt++;
	}
	l = x+1, r = y;
	while(l <= 10) {
		if(mps[l][r] == '.' || mps[l][r] == 'O') break;
		if(mps[l++][r] == 'X') cnt++;
	}
	return (cnt >= 4);
}
bool check2(int x, int y) {
	int cnt = 0;
	int l = x, r = y-1;
	while(r >= 1 ) {
		if(mps[l][r] == '.' || mps[l][r] == 'O') break;
		if(mps[l][r--] == 'X') cnt++;
	}
	l = x, r = y+1;
	while(r <= 10) {
		if(mps[l][r] == '.' || mps[l][r] == 'O') break;
		if(mps[l][r++] == 'X') cnt++;
	}
	return (cnt >= 4);
}
bool check3(int x, int y) {
	int cnt = 0;
	int l = x-1, r = y-1;
	while(l >= 1 && r >= 1) {
		if(mps[l][r] == '.' || mps[l][r] == 'O') break;
		if(mps[l--][r--] == 'X') cnt++;
	}
	l = x+1, r = y+1;
	while(l <= 10 && r <= 10) {
		if(mps[l][r] == '.' || mps[l][r] == 'O') break;
		if(mps[l++][r++] == 'X') cnt++;
	}
	return (cnt >= 4);
}
bool check4(int x, int y) {
	int cnt = 0;
	int l = x-1, r = y+1;
	while(l >= 1 && r <= 10) {
		if(mps[l][r] == '.' || mps[l][r] == 'O') break;
		if(mps[l--][r++] == 'X') cnt++;
	}
	l = x+1, r = y-1;
	while(l <= 10 && r >= 1) {
		if(mps[l][r] == '.' || mps[l][r] == 'O') break;
		if(mps[l++][r--] == 'X') cnt++;
	}
	return (cnt >= 4);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for(int i = 1; i <= 10; i++) {
		scanf("%s", mps[i]+1);
	}
	for(int i = 1; i <= 10; i++) {
		for(int j = 1; j <= 10; j++) {
			if(mps[i][j] == '.'){
				if(check1(i, j) || check2(i, j) || check3(i, j) || check4(i, j)) {
					puts("YES");
					return 0;
				}
			}
		}
	}
	puts("NO");
	return 0;
}
