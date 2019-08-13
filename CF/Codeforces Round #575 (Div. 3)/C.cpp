//
// Created by mile on 2019/7/24.
//

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    scanf("%d", &q);
    while(q--) {
        int x1 = -100000, y1 = -100000;
        int x2= 100000, y2 = 100000;
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            int x, y, a, b, c, d;
            scanf("%d%d%d%d%d%d", &x, &y, &a, &b, &c, &d);
            if(a == 0) x1 = max(x1, x);
            if(b == 0) y2 = min(y2, y);
            if(c == 0) x2 = min(x2, x);
            if(d == 0) y1 = max(y1, y);
        }
        if(x1 <= x2 && y1 <= y2) {
            printf("1 %d %d\n", x1, y1);
        }
        else puts("0");
    }
    return 0;
}