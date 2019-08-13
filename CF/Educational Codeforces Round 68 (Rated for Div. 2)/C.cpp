#include <bits/stdc++.h>

using namespace std;

string a, b, c;
int s[305], t[305], p[305], need[305];

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        memset(need, 0, sizeof(need));
        bool flag = true;
        cin>>a>>b>>c;
        int l, r;
        l = r = 0;
        while(l < a.size() && r < b.size())
        {
            if(a[l] == b[r])
            {
                ++l;
            }
            else need[b[r]-'a']++;
            ++r;
        }
        if(l != a.size()) flag = false;
        for(; r < b.size(); r++) need[b[r]-'a']++;
        for(int i = 0; i < c.size(); i++)
        {
            need[c[i]-'a']--;
        }
        for(int i = 0; i < b.size(); i++)
        {
            //cout<<b[i]<<" "<<need[b[i]-'a']<<endl;
            if(need[b[i]-'a'] > 0) flag = false;
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
