//
// Created by mile on 2019/8/2.
//

#include <bits/stdc++.h>

using namespace std;

int n, p;
struct Tmx {
    static const int N = 2;
    int a[2][2];
    Tmx() {
        a[0][0] = a[1][1] = 1;
        a[0][1] = a[1][0] = 0;
    }
};

Tmx operator * (const Tmx &a, const Tmx &b){
    Tmx c;
    c.a[0][0] = (1ll*a.a[0][0]*b.a[0][0]+1ll*a.a[0][1]*b.a[1][0])%p;
    c.a[0][1] = (1ll*a.a[0][0]*b.a[0][1]+1ll*a.a[0][1]*b.a[1][1])%p;
    c.a[1][0] = (1ll*a.a[1][0]*b.a[0][0]+1ll*a.a[1][1]*b.a[1][0])%p;
    c.a[1][1] = (1ll*a.a[1][0]*b.a[0][1]+1ll*a.a[1][1]*b.a[1][1])%p;
    return c;
}

Tmx power(Tmx a, long long t) {
    if(!t) return Tmx();
    if(t==1) return a;
    Tmx res = a; --t;
    for(; t; t>>=1, a=a*a) {
        if(t&1) res = res*a;
    }
    return res;
}

Tmx power(Tmx a, char s[]) {
    Tmx res;
    for(int i = n; i >= 1; --i) {
        if(s[i] != '0') res = res*power(a, s[i]-'0');
        a = power(a, 10);
    }
    return res;
}
char s [10000010];
int main()
{
    int x0, x1, A, B;
    scanf("%d%d%d%d", &x0, &x1, &A, &B);
    scanf("%s%d", s+1, &p);
    x1%=p, x0%=p, A%=p, B%=p;
    n = strlen(s+1);
    if(n == 1 && s[1] == '1') {
        printf("%d\n", x1);
        return 0;
    }
    Tmx a;
    a.a[0][0] = 0, a.a[0][1] = B;
    a.a[1][0] = 1, a.a[1][1] = A;
    a = power(a, s);
    Tmx b;
    b.a[0][0] = x0, b.a[0][1] = x1;
    b.a[1][0] = 0, b.a[1][1] = 0;
    b = b*a;
    printf("%d\n", b.a[0][0]);
    return 0;
}