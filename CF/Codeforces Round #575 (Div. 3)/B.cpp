//
// Created by mile on 2019/7/24.
//

#include <bits/stdc++.h>

using namespace std;

long long num[200005], id[200005];

int main()
{
    int q;
    scanf("%d", &q);
    while(q--) {
        int n, k;
        scanf("%d%d", &n, &k);
        int s = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%lld", &num[i]);
            if(num[i]%2 == 1) s++;
        }
        if(s < k) puts("NO");
        else {
            int cnt = 1;
            long long sum = 0;
            for(int i = 1; i<= n; i++) {
                sum += num[i];
                if(sum%2 == 1 && k > 1) id[cnt++] = i, k--, sum = 0;
            }
            sum = 0;
            for(int i = id[cnt-1]+1; i <= n; i++) sum += num[i];
            if(sum % 2 == 1) {
                puts("YES");
                id[cnt] = n;
                for(int i = 1; i <= cnt; i++) {
                    printf("%d ", id[i]);
                }
                puts("");
            }
            else {
                puts("NO");
            }
        }
    }
    return 0;
}