#include <bits/stdc++.h>

using namespace std;

int n, k, s;
int num[500005];
int cnt[1000006];

void add(int x)
{
    if(++cnt[x] == 1) s++;
}
void rem(int x)
{
    if(--cnt[x] == 0) s--;
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &num[i]);
    int r = 0;
    int ansl = 1, ansr = 1;
    for(int l = 1; l <= n; l++)
    {
        while(r < n)
        {
            r++;
            add(num[r]);
            if(s > k)
            {
                rem(num[r]);
                r--;
                break;
            }
        }
        if(ansr - ansl < r - l) ansl = l, ansr = r;
        rem(num[l]);
    }
    cout<<ansl<<" "<<ansr<<endl;
    return 0;
}
