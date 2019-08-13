#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n, k, a, b;
        cin>>k>>n>>a>>b;
        if(k - n*b <= 0) cout<<-1<<endl;
        else
        {
            k -= n*b;
            long long ans = (k-1)/(a-b);
            if(ans > n) ans = n;
            cout<<ans<<endl;
        }
    }
    return 0;
}
