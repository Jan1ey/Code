//
// Created by mile on 2019/7/18.
//

#include <bits/stdc++.h>

using namespace std;
const int maxn = 200005;

long long pre[maxn];

int main()
{
    for(int i = 1; i < maxn; i++)
    {
        pre[i] = pre[i-1]+i;
    }
    long long n, k;
    cin>>n>>k;
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(pre[i] - (n-i) == k)
        {
            ans = (n-i);
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
