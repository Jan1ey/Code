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
#define rep0(i, a, b) for(int i = a; i < b; ++i)
#define rep1(i, a, b) for(int i = a; i <= b; ++i)
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

const int maxn = 100005;

char s[maxn*20];
int stp[10][10][10][10], ans[10][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(stp, -1, sizeof(stp));

    rep1(i, 0, 9) {
        rep1(j, 0, 9) {
            rep1(k, 0, 9) {
                rep1(s, 0, 9) {
                    rep1(l, 0, 10) {
                        rep1(r, 0, 10) {
                            if ((k + i * l + j * r) % 10 == s) {
                                if(k == s && (i == 0 || j == 0) && l+r == 0) {
                                    stp[i][j][k][s] = 0;
                                    continue;
                                } else {
                                    if(l+r == 0) continue;
                                    //cout<<i<<" "<<j<<" "<<k<<" "<<s<<" "<<l<<" "<<r<<endl;
                                    if (stp[i][j][k][s] == -1) stp[i][j][k][s] = l + r;
                                    else stp[i][j][k][s] = min(stp[i][j][k][s], l + r);

                                }
                            }
                        }
                    }
                }
            }
        }
    }

    scanf("%s", s);
    int len = strlen(s);
    rep1(i, 0, 9) {
        rep1(j, 0, 9) {
            rep0(k, 0, len-1) {
                int a = s[k]-'0', b = s[k+1]-'0';
                //cout<<i<<" "<<j<<" "<<a<<" "<<b<<" "<<stp[i][j][a][b]<<endl;
                if(stp[i][j][a][b] != -1) {
                    ans[i][j] += stp[i][j][a][b] >= 1 ? stp[i][j][a][b]-1 : 0;
                } else {
                    ans[i][j] = -1; break;
                }
            }
        }
    }
    rep1(i, 0, 9) {
        rep1(j, 0, 9) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
