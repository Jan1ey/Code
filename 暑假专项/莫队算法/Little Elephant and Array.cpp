#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;
int n, m, blo, cnt, un;
int v[maxn], bl[maxn], num[maxn], b[maxn];
struct node
{
    int l, r, id, ans;
}s[maxn];

bool cmp1(node a, node b)
{
    if(bl[a.l] == bl[b.l]) return a.r < b.r;
    else return a.l < b.l;
}

bool cmp2(node a, node b)
{
    return a.id < b.id;
}

int get_id(int x)
{
    return lower_bound(b+1, b+1+un, x)-b;
}

void update(int a, int add)
{
    int y = v[a];
    int z = b[v[a]];
    if(add == 1)
    {
        if(num[y] == z) cnt--;
        num[y]++;
        if(num[y] == z) cnt++;
    }
    else
    {
        if(num[y] == z) cnt--;
        num[y]--;
        if(num[y] == z) cnt++;
    }
}

int main()
{
    //freopen("Text.txt", "r", stdin);
    int x = 1;
    scanf("%d%d", &n, &m);
    blo = sqrt(n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &v[i]);
        b[i] = v[i];
    }
    sort(b+1, b+n+1);
    un = unique(b+1, b+n+1) - b - 1;
    for(int i = 1; i <= n; i++) v[i] = get_id(v[i]);
    for(int i = 1; i <= n; i++) bl[i] = (i-1)/blo+1;
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d", &s[i].l, &s[i].r);
        s[i].id = i;
    }
    sort(s+1, s+m+1, cmp1);
    int l = 1, r = 0;
    for(int i = 1; i <= m; i++)
    {
        while(r < s[i].r) update(r+1, 1), r++;
        while(r > s[i].r) update(r, -1), r--;
        while(l < s[i].l) update(l, -1), l++;
        while(l > s[i].l) update(l-1, 1), l--;
        s[i].ans = cnt;
    }
    sort(s+1, s+m+1, cmp2);
    for(int i = 1; i <= m; i++) printf("%d\n", s[i].ans);
    return 0;
}
