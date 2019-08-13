//
// Created by mile on 2019/7/21.
//

//x = r1(mod a1)
//x = r2(mod a2)
//k1 * a1 + r1 = k2 * a2 + r2;
//k1 * a1 = (r2-r1) (mod a2)
//k1 * a1 + L * a2 = (r2-r1)
//x = a1 (mod r1)
//x + r1*l = a1;
/*
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

long long exgcd(long long a, long long b, long long &x, long long &y)
{
    if(!b) {x = 1, y = 0; return a;}
    long long ans = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return ans;
}

int main()
{
    int n;
    long long a1, r1, a2, r2, xx, yy;
    while(~scanf("%d", &n))
    {

        int f = 1;
        scanf("%lld%lld", &a1, &r1);
        for(int i = 2; i <= n; i++)
        {
            scanf("%lld%lld", &a2, &r2);
            long long d = exgcd(a1, a2, xx, yy);
            if((r2-r1)%d) f = 0;
            xx = (r2-r1)/d*xx;
            long long l = a2/d;
            xx = (xx%l+l)%l;
            r1 = xx*a1+r1;
            a1 = a1/d*a2;
            r1 %= a1;
        }
        //cout<<r1<<endl;
        if(r1 < 0) r1 += a1;
        if(!f) {puts("-1");}
        else cout<<r1<<endl;
    }
    return 0;
}
*/