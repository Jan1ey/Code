//
// Created by mile on 2019/8/3.
//
//HDU-4122
//st表

#include <bits/stdc++.h>

using namespace std;
const int maxn = 100005;

int n, m, h, r, s, t;

long long charge[maxn];
long long st[maxn][20];
int log2n[maxn];

int get_month(char s[])
{
    if(!strcmp(s, "Jan")) return 1;
    if(!strcmp(s, "Feb")) return 2;
    if(!strcmp(s, "Mar")) return 3;
    if(!strcmp(s, "Apr")) return 4;
    if(!strcmp(s, "May")) return 5;
    if(!strcmp(s, "Jun")) return 6;
    if(!strcmp(s, "Jul")) return 7;
    if(!strcmp(s, "Aug")) return 8;
    if(!strcmp(s, "Sep")) return 9;
    if(!strcmp(s, "Oct")) return 10;
    if(!strcmp(s, "Nov")) return 11;
    if(!strcmp(s, "Dec")) return 12;
}

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

bool isleap(int y) {
    if(y%400 == 0 || (y%100 != 0 && y%4 == 0)) return true;
    else return false;
}

struct date {
    char s[10];
    int year, month, day, h, r;
};

date mc[3000];

long long rmq(int x, int y) {
    int k = log2n[y-x+1];
    return min(st[x][k], st[y-(1<<k)+1][k]);
}

int get_h(date x) {
    int tmp = 0;
    for(int i = 2000; i < x.year; i++) {
        if(isleap(i)) tmp += 366*24;
        else tmp += 365*24;
    }
    for(int i = 1; i < get_month(x.s); i++) {
        tmp += days[i]*24;
    }
    if(isleap(x.year) && get_month(x.s) > 2) tmp += 24;
    tmp += (x.day-1)*24;
    tmp += x.h+1;
    return tmp;
}

int main()
{
    while(~scanf("%d%d", &n, &m) && n+m) {
        for(int i = 1; i <= n; i++) {
            scanf("%s%d%d%d%d", mc[i].s, &mc[i].day, &mc[i].year, &mc[i].h, &mc[i].r);
        }
        scanf("%d%d", &t, &s);
        for(int i = 1; i <= m; i++) {
            scanf("%lld", charge+i);
            charge[i] += (m-i)*s;
        }
        log2n[0] = -1;
        for(int i = 1; i <= m; ++i) {
            log2n[i] = ((i&(i-1)) == 0) ? log2n[i-1]+1 : log2n[i-1];
            st[i][0] = charge[i];
        }
        for(int j = 1; j <= log2n[m]; j++) {
            for(int i = 1; i + (1<<j) - 1 <= m; i++) {
                st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
            }
        }
        long long ans = 0;
        for(int i = 1; i <= n; i++) {
            mc[i].h = get_h(mc[i]);
            long long tmp = rmq(max(1, mc[i].h-t), mc[i].h);
            tmp -= (m-mc[i].h)*s;
            ans += 1ll*mc[i].r*tmp;
        }
        printf("%lld\n", ans);
    }
    return 0;
}