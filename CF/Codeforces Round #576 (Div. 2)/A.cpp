//
// Created by mile on 2019/7/30.
//
//Codeforces Round #576 (Div. 2) A

#include <bits/stdc++.h>

#define pb push_back
#define ps push
#define mp make_pair
using namespace std;
const int maxn = 100005;
typedef long long ll;

int a[maxn], b[maxn], num[maxn];

int main()
{
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    for(int i = 1; i <= n; i++) scanf("%d", &num[i]);
    for(int i = 1; i <= n; i++) {
        bool flag = true;
        int l = max(i-x, 1), r = min(i+y, n);
        for(int j = i-1; j >= l; j--) {
            if(num[j]<num[i]) flag =false;
        }
        for(int j = i+1; j <= r; j++) {
            if(num[i] > num[j]) flag = false;
        }
        if(flag){
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}

