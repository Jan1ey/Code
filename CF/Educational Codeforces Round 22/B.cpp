#include <bits/stdc++.h>

#define int_128 long long
using namespace std;

int_128 a[105], b[105];
vector<int_128> ve;
int_128 ans = 0;

int main()
{
    int_128 x, y, l, r;
    cin>>x>>y>>l>>r;
    a[0] = b[0] = 1;
    int cnt1, cnt2;
    cnt1 = cnt2 = 0;
    for(int i = 1; i <= 100 && a[i-1] <= 1e18/x; i++)
    {
        a[i] = a[i-1]*x;
        cnt1++;
    }
    for(int i = 1; i <= 100 && b[i-1] <= 1e18/y ; i++)
    {
        b[i] = b[i-1]*y;
        cnt2++;
    }
    //cout<<cnt1<<" "<<cnt2<<endl;
    for(int i = 0; i <= cnt1; i++)
    {
        for(int j = 0; j <= cnt2; j++)
        {
            //cout<<1<<endl;
            if(a[i] <= 1e18-b[j]) ve.push_back(a[i]+b[j]);
        }
    }
    sort(ve.begin(), ve.end());
    auto it = unique(ve.begin(), ve.end());
    ve.erase(it, ve.end());
    //cout<<ve[0]<<endl;
    int cntl, cntr;
    cntl = 0, cntr = ve.size()-1;
    vector<long long> s;
    for(int i = 0; i < ve.size(); i++)
    {
        if(ve[i] >= l && ve[i] <= r)
        {
            //cout<<ve[i]<<endl;
            s.push_back(ve[i]);
        }
    }
    if(s.size() == 0)
    {
        cout<<(r-l+1)<<endl;
        return 0;
    }
    ans = max(ans, s[0]-l);
    for(int i = 1; i < s.size(); i++)
    {
        ans = max(ans, s[i]-s[i-1]-1);
    }
    ans = max(ans, r-s[s.size()-1]);
    cout<<ans<<endl;
    return 0;
}
