//
// Created by mile on 2019/7/27.
//

#include <bits/stdc++.h>

using namespace std;

char s[100005];
int pre[100005];
int num[5];
long long ans = 0;

int main()
{
    scanf("%s", s+1);
    long long ans = 0;
    num[0] = 1;
    int len = strlen(s+1);
    for(int i = 1; i <= strlen(s+1); i++){
        if(s[i] == '0') ans++;
        pre[i] = pre[i-1]+s[i]-'0';
        pre[i] %= 3;
        if(i >= 2 && s[i] == '0'&& s[i-1] == '0') {
            ans += num[pre[i]]-1;
        }
        num[pre[i]]++;
    }
    printf("%lld\n", ans);
    return 0;
}