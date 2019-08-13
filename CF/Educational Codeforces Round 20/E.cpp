//
// Created by mile on 2019/7/18.
//

#include <bits/stdc++.h>

using namespace std;

string s;
int dp[1010][3030];
int n, k;

int main() {
    cin >> n >> k >> s;
    //cout<<s<<endl;
    for (int i = 0; i < 1010; i++)
        for (int j = 0; j < 3030; j++)
            dp[i][j] = -1;
    dp[0][1500] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1500 - k + 1; j <= 1500 + k - 1; ++j) {
            if (dp[i][j] == -1) continue;
            if (s[i] == 'W' || s[i] == '?') dp[i + 1][j + 1] = j;
            if (s[i] == 'L' || s[i] == '?') dp[i + 1][j - 1] = j;
            if (s[i] == 'D' || s[i] == '?') dp[i + 1][j] = j;
        }
    }
    //cout<<1<<endl;
    if (dp[n][1500 + k] == -1 && dp[n][1500 - k] == -1) {
        puts("NO");
        return 0;
    }
    int f = 1500 + k;
    if (dp[n][f] == -1) f = 1500 - k;
    //cout<<f<<endl;
    for (int i = n - 1; i >= 0; i--) {
        int g = f;
        f = dp[i + 1][f];
        //cout<<g<<" "<<f<<endl;
        if (g - f == 1) s[i] = 'W';
        if (g - f == 0) s[i] = 'D';
        if (g - f == -1) s[i] = 'L';
        //cout<<1<<endl;
    }
    //cout<<1<<endl;
    cout << s << endl;
    return 0;
}
