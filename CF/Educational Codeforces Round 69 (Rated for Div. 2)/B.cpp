//
// Created by mile on 2019/8/5.
//

#include <bits/stdc++.h>

using namespace std;

int num[100005];

int main()
{
    int n;
    scanf("%d", &n);
    long long sum = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
        sum += num[i];
    }
    sort(num+1, num+n+1);
    if(sum%2 || sum-num[n] < num[n]) puts("NO");
    else puts("YES");
    return 0;
}