#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--){
    long long n, s, t;
    cin>>n>>s>>t;
    long long k = s+t-n;
    long long ans = max(s-k, t-k)+1;
    cout<<ans<<endl;
    }
    return 0;
}
