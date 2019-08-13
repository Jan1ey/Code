#include <bits/stdc++.h>

using namespace std;

char s1[1000006], s2[1000006];

int main()
{
    scanf("%s", s1);
    scanf("%s", s2);
    int cnt1, cnt2;
    cnt1 = cnt2 = 0;
    for(int i = 0; i < strlen(s1); i++)
    {
        if(s1[i] == '0') cnt1++;
        else break;
    }
    for(int i = 0; i < strlen(s2); i++)
    {
        if(s2[i] == '0') cnt2++;
        else break;
    }
    int len1 = strlen(s1), len2 = strlen(s2);
    //cout<<len1<<" "<<cnt1<<" "<<len2<<" "<<cnt2<<endl;
    if(len1 - cnt1 > len2 - cnt2 ) cout<<">"<<endl;
    else if(len1 - cnt1 < len2 - cnt2) cout<<"<"<<endl;
    else
    {
        for(int i = cnt1, j = cnt2; i < len1, j < len2; i++, j++)
        {
            if(s1[i] == s2[j]) continue;
            else if(s1[i] < s2[j])
            {
                cout<<"<"<<endl;
                return 0;
            }
            else if(s1[i] > s2[j])
            {
                cout<<">"<<endl;
                return 0;
            }
        }
        cout<<"="<<endl;
    }
    return 0;
}
