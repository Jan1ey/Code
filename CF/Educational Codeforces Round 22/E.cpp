#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

vector<int> pos[maxn];
int n, k, m;
int rt[maxn], v[maxn*20], lc[maxn*20], rc[maxn*20], idx;

void t_insert(int &rt, int l, int r, int num)
{
    lc[++idx] = lc[rt], rc[idx] = rc[rt], v[idx] = v[rt]+1, rt = idx;
    //cout<<"rt: "<<rt<<" lc[rt]: "<<lc[rt]<<" rc[rt]: "<<rc[rt]<<" v[rt]: "<<v[rt]<<endl;
    if(l == r) return ;
    int mid = (l+r)>>1;
    if(num <= mid) t_insert(lc[rt], l, mid, num);
    else t_insert(rc[rt], mid+1, r, num);
}

int query(int L, int R, int l, int r, int num)
{
    if(r <= num) return v[R]-v[L];
    int mid = (l+r)>>1, ans = 0;
    ans = query(lc[L], lc[R], l, mid, num);
    if(num > mid) ans += query(rc[L], rc[R], mid+1, r, num);
    return ans;
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 1, x; i <= n; i++)
    {
        scanf("%d", &x);
        pos[x].push_back(i);
        int sz = pos[x].size();
        if(sz > k) sz = pos[x][sz-k-1];
        else sz = 0;
        rt[i] = rt[i-1];
        t_insert(rt[i], 0, n, sz);
    }
    scanf("%d", &m);
    int last = 0;
    while(m-- > 0)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l = (l+last)%n+1, r = (r+last)%n+1;
        if(l > r) swap(l, r);
        printf("%d\n", last = query(rt[l-1], rt[r], 0, n, l-1) );
    }
    return 0;
}
