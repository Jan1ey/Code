//
// Created by mile on 2019/8/2.
//

#include <iostream>
#include <queue>
#include <cstdio>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 1000005;
struct fx {
    int i, s;
    bool operator < (const fx& a)const {
        return s > a.s;
    }
};

priority_queue<fx> pq;

int vis[maxn], dp[maxn];

int main()
{
    int n, l;
    scanf("%d%d", &n, &l);
    int a, b;
    scanf("%d%d", &a, &b);
    for(int i = 1; i <= n; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        ++vis[l+1];
        --vis[r];
    }
    a <<= 1; b <<= 1;
    int cnt = 0;
    for(int i = 0; i <= l; i++) {
        dp[i] = INF;
        cnt += vis[i];
        vis[i] = cnt>0;
    }
    for(int i = a; i <= b; i += 2) {
        if(!vis[i]) {
            dp[i] = 1;
            if(i <= b-a+2) pq.push((fx){i, dp[i]});
        }
    }
    for(int i = b+2; i <= l; i += 2) {
        if(!vis[i]) {
            fx tp;
            while(!pq.empty()) {
                tp = pq.top();
                if(tp.i < i-b) pq.pop();
                else break;
            }
            if(!pq.empty()) {
                dp[i] = dp[tp.i]+1;
            }
        }
        if(dp[i+2-a] != INF) {
            pq.push((fx){i+2-a, dp[i+2-a]});
        }
    }
    if(dp[l] == INF) {
        printf("%d\n", -1);
    } else {
        printf("%d\n", dp[l]);
    }
    return 0;
}