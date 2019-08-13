//
// Created by mile on 2019/7/17.
//

#include <Bits/stdc++.h>

using namespace std;
const int maxn = 200005;

long long num[maxn];

int main()
{
    long long n, k;
    cin>>n>>k;
    int gcd = -1;
    if(k >= 141420)
    {
        cout<<-1<<endl;
        return 0;
    }
    long long ans = ((k+1)*k)/2;
    for(int i = 1; i <= sqrt(n); i++)
    {
        if(n%i == 0)
        {
            if(i >= ans)
            {
                gcd = n/i;
                break;
            }
            else if(n/i >= ans)
            {
                gcd = i;

            }
        }
    }
    if(gcd == -1)
        cout<<-1<<endl;
    else
    {
        long long sum = 0;
        for(int i = 1; i < k; i++)
            cout<<1l*i*gcd<<" ", sum += i*gcd;
        cout<<n-sum<<endl;
    }
    return 0;
}
