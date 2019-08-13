//
// Created by mile on 2019/7/24.
//

#include <bits/stdc++.h>

using namespace std;

int q, n, k;
char str[] = "RGB";
char ch[200005];
int acc[200005];

int Get(int x) {
    for(int i = 1; i <= n; i++) {
        acc[i] = acc[i-1] + (str[x] != ch[i]);
        x = (x+1)%3;
    }
    int res = acc[k];
    for(int i = k+1; i <= n; i++) {
        res = min(res, acc[i] - acc[i-k]);
    }
    return res;
}

int main()
{
    scanf("%d", &q);
    while(q--) {
        scanf("%d%d", &n, &k);
        scanf("%s", ch+1);
        int res = min(min(Get(0), Get(1)), Get(2));
        printf("%d\n", res);
    }
    return 0;
}