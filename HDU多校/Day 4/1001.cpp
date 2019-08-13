//
// Created by mile on 2019/7/31.
//

#include <bits/stdc++.h>

using namespace std;

int num[200005];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        int ans = 0;
        scanf("%d", &n);
        for(int i = 2; i <= n; i++) {
            int k = 1;
            int cnt = i;
            while(cnt&1) cnt >>= 1, k <<= 1;
            if(k > n) k = 1;
            num[i] = k;
            ans += k&i;
        }
        printf("%d\n", ans);
        for(int i = 2; i < n; i++) {
            printf("%d ", num[i]);
        }
        printf("%d\n", num[n]);
    }
    return 0;
}