#include <bits/stdc++.h>

using namespace std;
const int maxn = 200005;

int n;
int num[maxn], pos[maxn], L[maxn], R[maxn];
pair<int, int> de[maxn];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &num[i]), pos[num[i]] = i;
    int hd = 1, bk = 0;
    for(int i = 1; i <= n; i++)
    {
        while(hd <= bk && de[bk].first <= num[i]) --bk;
        L[i] = de[bk].second;
        de[++bk].first = num[i], de[bk].second = i;
    }
    hd = 1, bk = 0;
    de[bk].second = n+1;
    for(int i = n; i >= 1; i--)
    {
        while(hd <= bk && de[bk].first <= num[i]) --bk;
        R[i] = de[bk].second;
        de[++bk].first = num[i], de[bk].second = i;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i-L[i] < R[i]-i)
        {
            for(int j = L[i]+1; j < i; j++)
            {
                if(pos[num[i]-num[j]] > i && pos[num[i]-num[j]] < R[i]) ans++;
            }
        }
        else
        {
            for(int j = R[i]-1; j > i; j--)
            {
                if(pos[num[i]-num[j]] > L[i] && pos[num[i]-num[j]] < i) ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
