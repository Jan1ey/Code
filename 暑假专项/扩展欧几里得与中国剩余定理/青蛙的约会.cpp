//
// Created by mile on 2019/7/21.
//

//(m-n)t　= (y-x)(mod L)
//(m-n)t+l*k =(y-x)
/*
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

long long exgcd(long long a, long long b, long long &x, long long &y)
{
    if(!b) {x = 1, y = 0; return  a;}
    long long ans = exgcd(b, a%b, x, y);
    long long t = x; x = y; y = t-a/b*y;
    return ans;
}

int main()
{
    long long x, y, n, m, l, xx, yy;
    while(cin>>x>>y>>m>>n>>l)
    {
        long long d = exgcd((n-m), l, xx, yy);
        if((x-y)%d)
        {
            puts("Impossible");
            continue;
        }
        xx = xx*(x-y)/d;
        xx = (xx%(l/d)+l/d)%(l/d);
        cout<<xx<<endl;
    }
    return 0;
}
*/