//
// Created by mile on 2019/7/25.
//

#include <bits/stdc++.h>

using namespace std;

struct node {
    int x; int y;
}v[2005];

bool cmp(node a, node b) {
    if(a.x != b. x) {
        return a.x < b.x;
    } else {
        return a.y > b.y;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d%d", &v[i].x, &v[i].y);
        sort(v+1, v+n+1, cmp);
        printf("%d %d %d %d\n", v[n/2].x+1, 9990000+v[n/2].y, v[n/2].x-1, -9990000+v[n/2].y);
    }
    return 0;
}