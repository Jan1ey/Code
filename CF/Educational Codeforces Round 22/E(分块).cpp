#include <bits/stdc++.h>

#define pb push_back
using namespace std;

const int maxn = 100005;


int n, k, block;
int a[maxn], blo[maxn], L[maxn], R[maxn], pos[maxn];
vector<int> ve[maxn], tmp[maxn];

int query(int l, int r)
{
    int cnt = 0;
    for(int i = l; i <= min(r, R[l]); i++)
    {
            if(pos[i] > r) cnt++;
    }
    //cout<<cnt<<endl;
    if(blo[l] != blo[r])
        for(int i = L[r]; i <= r; i++)
        {
            //cout<<L[r]<<" "<<r<<endl;
            //cout<<pos[i]<<endl;
            if(pos[i] > r) cnt++;
        }
    for(int i = blo[l]+1; i < blo[r]; i++)
    {
        int up = upper_bound(tmp[i].begin(), tmp[i].end(), r)-tmp[i].begin();
        up = tmp[i].size()-up;
        cnt += up;
        //cout<<cnt<<endl;
    }
    return cnt;
}

int main()
{
    scanf("%d%d", &n, &k);
    block = sqrt(n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        ve[a[i]].pb(i);
    }
    for(int i = 1; i <= n; i++)
    {
        blo[i] = (i-1)/block+1;
        L[i] = (blo[i]-1)*block+1;
        R[i] = blo[i]*block;
    }
    for(int i = 1; i <= maxn; i++)
    {
        for(int j = 0; j < ve[i].size(); j++)
        {
            if(j + k >= ve[i].size())
            {
                pos[ve[i][j]] = n+1;
            }
            else pos[ve[i][j]] = ve[i][j+k];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        tmp[blo[i]].pb(pos[i]);
    }
    for(int i = 1; i <= blo[n]; i++)
    {
        sort(tmp[i].begin(), tmp[i].end());
    }
    int m;
    scanf("%d", &m);
    int ans = 0;
    while(m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l = (l+ans)%n+1;
        r = (r+ans)%n+1;
        if(l > r) swap(l, r);
        //cout<<l<<" "<<r<<endl;
        ans = query(l, r);
        printf("%d\n", ans);
    }
    return 0;
}
