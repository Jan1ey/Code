//
// Created by mile on 2019/7/17.
//

#include <Bits/stdc++.h>

using namespace std;

int num[1005];
int ty[1005];

int main()
{
    int n, k;
    cin>>n>>k;
    for(int i = 1; i <= n; i++) cin>>num[i];
    for(int i = 1; i <= n; i++)
    {
        ty[num[i]]++;
    }
    int ans = 0, sum = 0;
    for(int i = 1; i <= k; i++)
    {
        //cout<<ty[i]<<endl;
        int x = ty[i]%2, y = ty[i]/2;
        ans += y*2, sum += y;
        ty[i] = x;
    }
    if(sum >= (n+1)/2)
    {
        cout<<ans<<endl;
    }
    else
    {
        for(int i = 1; i <= k; i++)
        {
            if(sum < (n+1)/2 && ty[i] != 0) ans += 1, sum += 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}