#include <bits/stdc++.h>
#define lid id<<1
#define rid id<<1|1

#define maxn 300005
using namespace std;

int s[maxn];
queue<int> ve[300005];
int b[maxn];
struct node
{
    int l, r, v;
}tr[maxn*4];

void push_up(int id)
{
    tr[id].v = min(tr[lid].v, tr[rid].v);
}

void build(int id, int l, int r)
{
    tr[id].l = l; tr[id].r = r;
    if(l == r)
    {
        tr[id].v = s[l];
        return ;
    }
    int mid = (l+r)>>1;
    build(lid, l, mid);
    build(rid, mid+1, r);
    push_up(id);
}
void update(int id, int l, int c)
{
    if(l == tr[id].l && tr[id].r == l)
    {
        tr[id].v = c;
        return ;
    }
    int mid = (tr[id].l+tr[id].r)>>1;
    if(l<=mid) update(lid, l, c);
    else update(rid, l, c);
    push_up(id);
}

int query(int id, int l, int r)
{
    if(tr[id].l >= l && tr[id].r <= r) return tr[id].v;
    int mid = (tr[id].l+tr[id].r)>>1;
    if(r <= mid) return query(lid, l, r);
    else if(l > mid) return query(rid, l, r);
    else
    {
        int a = query(lid, l, mid);
        int b = query(rid, mid+1, r);
        return min(a, b);
    }
}

int main()
{
    //freopen("Text.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        //cout<<t<<endl;
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &s[i]), ve[s[i]].push(i);
        for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
        build(1, 1, n);
        int flag = 1;
        for(int i = 1; i <= n; i++)
        {
            if(!ve[b[i]].empty())
            {
                int v = ve[b[i]].front();
                ve[b[i]].pop();
                if(query(1, 1, v) != b[i])
                        flag = 0;
                else update(1, v, INT_MAX);
            }
            else  flag = 0;
            if(!flag) break;
        }
        for(int i = 1; i <= n; i++)
            while(!ve[s[i]].empty()) ve[s[i]].pop();
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}
