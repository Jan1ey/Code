#include <bits/stdc++.h>

using namespace std;

const int maxn = 50005;
long long ans;
int blo;
int bl[maxn], s[maxn];
long long col[maxn];
struct node
{
    int l, r, id;
    long long a, b;
}q[maxn];
bool cmp2(node a, node b)
{
    if(bl[a.l] == bl[b.l]) return a.r < b.r;
    else return a.l < b.l;
}

bool cmp(node a, node b)
{
    return a.id < b.id;
}

long long gcd(long long a, long long b)
{
    if(b == 0) return a;
    else return gcd(b, a%b);
}

void update(int q, int add)
{
    ans -= col[s[q]]*col[s[q]];
    col[s[q]] += add;
    ans += col[s[q]]*col[s[q]];
}

int main()
{
    //freopen("Text.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &s[i]);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    blo = sqrt(n);
    for(int i = 1; i <= n; i++)
    {
        bl[i] = (i-1)/blo+1;
    }
    sort(q+1, q+m+1, cmp2);
    int l = 1, r = 0;
    for(int i = 1; i <= m; i++)
    {
        while(r < q[i].r) update(r+1, 1), r++;
        while(r > q[i].r) update(r, -1), r--;
        while(l < q[i].l) update(l, -1), l++;
        while(l > q[i].l) update(l-1, 1), l--;
        if(q[i].l == q[i].r)
        {
            q[i].a = 0, q[i].b = 1;
            continue;
        }
        q[i].a = ans-(q[i].r-q[i].l+1);
        q[i].b = (long long)(q[i].r-q[i].l+1)*(q[i].r-q[i].l);
        long long k = gcd(q[i].a, q[i].b);
        q[i].a /= k, q[i].b /= k;
    }
    sort(q+1, q+m+1, cmp);
    for(int i = 1; i <= m; i++)
    {
        printf("%lld/%lld\n", q[i].a, q[i].b);
    }
    return 0;
}
