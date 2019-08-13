#include <bits/stdc++.h>

using namespace std;

const int maxn = 30005;
const int maxm = 1000005;
int cnt;
int v[maxn], bl[maxn], num[maxm];
struct node
{
    int l, r, id, ans;
}s[200005];

bool cmp1(node a, node b)
{
    if(bl[a.l] == bl[b.l]) return a.r < b.r;
    else return a.l < b.l;
}

bool cmp2(node a, node b)
{
    return a.id < b.id;
}

void update(int a, int add)
{
    if(num[a] == 1)
    {
        if(add == -1) cnt--, num[a] = 0;
        else num[a]++;
    }
    else if(num[a] == 0) cnt++, num[a]++;
    else num[a] += add;
}

int main()
{
   // freopen("Text.txt", "r", stdin);
    int n;
    cnt =0;
    scanf("%d", &n);
    int blo = sqrt(n);
    for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
    int m;
    scanf("%d", &m);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d", &s[i].l, &s[i].r);
        s[i].id = i;
    }
    for(int i = 1; i <= n; i++) bl[i] = (i-1)/blo+1;
    sort(s+1, s+m+1, cmp1);
    int l = 1, r = 0;
    for(int i = 1; i <= m; i++)
    {
        //cout<<"query"<<s[i].l<<" "<<s[i].r<<endl;
        while(r < s[i].r) update(v[r+1], 1), r++;
        while(r > s[i].r) update(v[r], -1), r--;
        while(l < s[i].l) update(v[l], -1), l++;
        while(l > s[i].l) update(v[l-1], 1), l--;
        s[i].ans = cnt;
    }
    sort(s+1, s+1+m, cmp2);
    for(int i = 1; i <= m; i++) printf("%d\n", s[i].ans);
    return 0;
}
