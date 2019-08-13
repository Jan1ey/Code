#include <bits/stdc++.h>

using namespace std;
const int maxn = 200005;

int num[maxn];
vector<int> ve;

int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>num[i];
        if(num[i] == 0) ve.push_back(i);
    }
    for(int i = 1; i <= n; i++)
    {
        auto it = lower_bound(ve.begin(), ve.end(), i);
        if(it == ve.end()) it--;
        if(it != ve.begin())
        {
            int pos = min(abs(*(it-1)-i), abs(*it-i));
            cout<<pos<<" ";
        }
        else
        {
            int pos = abs(*it-i);
            cout<<pos<<" ";
        }
    }
    return 0;
}