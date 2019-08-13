#include <bits/stdc++.h>

using namespace std;

char ch[1000006];
int num[1000006];
int k, t;

bool check(int len){
    int x = 0, ans = 0;
    for(int i = 1; i <= t; i++){
        if(num[i] > len) return false;
        if(x+num[i] > len) ans++, x = num[i];
        else x += num[i];
    }
    ans++;
    //out<<len<<" "<<ans<<endl;
    if(ans <= k) return true;
    else return false;
}

int main()
{
    scanf("%d", &k);
    getchar();
    gets(ch);
    int cnt = 0;
    int sum = 0;
    //puts(ch);
    for(int i = 0; i < strlen(ch); i++) {
        if (ch[i] == ' ' || ch[i] == '-') num[++t] = ++cnt, cnt = 0;
        else cnt++;
}
    num[++t] = cnt;
    //for(int i = 1; i <= t; i++) cout<<num[i]<<endl;
    for(int i = 1; i <= t; i++)
        sum += num[i];
    int l = 1, r = sum;
    int ans = 1;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid)) {
            //cout<<1<<endl;
            r = mid - 1, ans = mid;
        }else{
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}