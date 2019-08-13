#include <bits/stdc++.h>

#define maxn 100005
using namespace std;

int n;
int tree[maxn];

int lowbit(int x)
{
    return x&(-x);
}

void update(int i, int add)
{
    for(int j = i; j <= n; j += lowbit(j))
    {
        tree[j] += add;
    }
}

int query(int l, int r)
{
    int ans1 = 0;
    for(int i = r; i > 0; i -= lowbit(i))
    {
        ans1 += tree[i];
    }
    int ans2 = 0;
    for(int i = l-1; i > 0; i -= lowbit(i))
    {
        ans2 += tree[i];
    }
    return ans1-ans2;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int m;
        scanf("%d", &m);
        update(i, m);
    }
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r)/10);
    }
    return 0;
}
