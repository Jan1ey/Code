#include <bits/stdc++.h>

using namespace std;

vector<int> ve[205];
int cnt[205];
string s1, s2;
int ans;


int main()
{
    int n;
    cin>>n;
    cin>>s1;
    for(int i = 0; i < s1.size(); i++) ve[s1[i]].push_back(i);
    int m;
    cin>>m;
    while(m--)
    {
        ans = 0;
        cin>>s2;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < s2.size(); i++)
        {
            cnt[s2[i]]++;
            ans = max(ans, ve[s2[i]][cnt[s2[i]]-1]);
        }
        cout<<ans+1<<endl;
    }
    return 0;
}
