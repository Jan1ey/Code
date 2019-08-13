#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    int n;
    cin>>n;
    cin>>s;
    int ans = 1;
    int cnt = 0;
    for(int i = 0; i <= n; i++)
        if(s[i] == '1') cnt++;
    if(cnt != n-cnt) cout<<1<<endl, cout<<s<<endl;
    else
    {
        int flag = 1;
        int cnt0, cnt1;
        cnt0 = cnt1 = 0;
        cout<<2<<endl;
        for(int i = 0; i < n; i++)
        {
            cout<<s[i];
            if(s[i] == '0') cnt0++;
            else cnt1++;
            if(cnt0 != cnt1 && cnt1 && flag) cout<<" ", flag = 0;
        }
        cout<<endl;
    }
    return 0;
}
