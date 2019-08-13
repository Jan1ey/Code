#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

struct node
{
    int l, r;
}tim[maxn];
int pro[maxn];

int main()
{
    int n, m;
    cin>>n;
    int sum = 0;
    for(int i = 1; i <= n; i++) cin>>pro[i], sum += pro[i];
    cin>>m;
    for(int i = 1; i <= m; i++) cin>>tim[i].l>>tim[i].r;
    for(int i = 1; i <= m; i++)
    {
        if(sum <= tim[i].r && sum >= tim[i].l)
        {
            cout<<sum<<endl;
            return 0;
        }
        else if(sum <= tim[i].r)
        {
            cout<<tim[i].l<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
