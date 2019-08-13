#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>

#define INT_MAX 0x3f3f3f3f
using namespace std;

const int maxn = 1000005;
int num[maxn];
struct node
{
    int first, second;
} lde[maxn], sde[maxn];
int mx[maxn], mn[maxn];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int lhd = 1, lbk = 0, shd = 1, sbk = 0;
    for(int i = 1; i <= n; i++) scanf("%d", &num[i]);
    //sde[0].first = -INT_MAX; lde[0].first = INT_MAX;
    for(int i = 1; i <= k; i++)
    {
        while(sbk >= shd && sde[sbk].first >= num[i]) sbk--;
        sde[++sbk].first = num[i];
        sde[sbk].second = i;
        while(lbk >= lhd && lde[lbk].first <= num[i]) lbk--;
        lde[++lbk].first = num[i];
        lde[lbk].second = i;
    }
    for(int i = k; i <= n; i++)
    {
        while(sbk >= shd && sde[sbk].first >= num[i]) sbk--;
        sde[++sbk].first = num[i];
        sde[sbk].second = i;
        //cout<<hd<<endl;
        while(sbk >= shd && sde[shd].second <= i-k) shd++;
        //printf("%d%c", de[hd].first, " \n"[i==n]);
        while(lbk >= lhd && lde[lbk].first <= num[i]) lbk--;
        lde[++lbk].first = num[i];
        lde[lbk].second = i;
        while(lbk >= lhd && lde[lhd].second <= i-k) lhd++;
        mx[i] = lde[lhd].first; mn[i] = sde[shd].first;
        //printf("%d%c", de[hd].first, " \n"[i==n]);
    }
    for(int i = k; i < n; i++)
    {
        printf("%d ", mn[i]);
    }
    printf("%d\n", mn[n]);
    for(int i = k; i < n; i++)
    {
       printf("%d ", mx[i]);
    }
    printf("%d\n", mx[n]);
    return 0;
}
