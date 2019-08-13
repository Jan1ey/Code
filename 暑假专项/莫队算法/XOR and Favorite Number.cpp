#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;
const int maxm = 10000005;
int n, m, k, blo;
long long ans;
long long  v[maxn], cnt[maxm], sum[maxn];
struct node
{
    int l, r, id;
    long long ans;
}s[maxn];

bool cmp1(node a, node b)
{
    if((a.l-1)/blo+1 == (b.l-1)/blo+1) return a.r < b.r;
    else return a.l < b.l;
}

bool cmp2(node a, node b)
{
    return a.id < b.id;
}

void update(int a, int add)
{
    long long x = sum[a];
    if(add == 1)
    {
        ans += cnt[x^k];
        cnt[x]++;
    }
    else
    {
        cnt[x]--;
        ans -= cnt[x^k];
    }
}

int main()
{
    //freopen("Text.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    blo = sqrt(n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%I64d", &v[i]);
        sum[i] = sum[i-1]^v[i];
    }
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d", &s[i].l, &s[i].r);
        s[i].id = i;
        s[i].l -= 1;
    }
    sort(s+1, s+m+1, cmp1);
    int l = 0, r = 0;
    cnt[0] = 1;
    for(int i = 1; i <= m; i++)
    {
        while(r < s[i].r) update(r+1, 1), r++;
        while(r > s[i].r) update(r, -1), r--;
        while(l < s[i].l) update(l, -1), l++;
        while(l > s[i].l) update(l-1, 1), l--;
        s[i].ans = ans;
    }
    sort(s+1, s+m+1, cmp2);
    for(int i = 1; i <= m; i++) printf("%I64d\n", s[i].ans);
    return 0;
}
