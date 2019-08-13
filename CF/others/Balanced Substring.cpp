//
// Created by mile on 2019/7/25.
//
//cf 873B	Balanced Substring


//
// Created by mile on 2019/7/25.
//

#include<bits/stdc++.h>
using namespace std;

int n;
const int maxn=100005;
char s[maxn];
int num[maxn], pos[maxn*2];

int main()
{
    int n;
    scanf("%d%s", &n, s+1);
    int ans = 0;
    memset(pos, -1, sizeof(pos));
    pos[n] = 0;
    for(int i = 1; i <= n; i++) {
        num[i] = num[i-1]+(s[i] == '0' ? -1 : 1);
        if(pos[num[i]+n] == -1) pos[num[i]+n] = i;
        else {
            ans = max(ans, i - pos[num[i]+n]);
        }
    }
    printf("%d\n", ans);
    return 0;
}