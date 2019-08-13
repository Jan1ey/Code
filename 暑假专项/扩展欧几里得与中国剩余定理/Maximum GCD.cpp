//
// Created by mile on 2019/7/21.
//
/*
#include <bits/stdc++.h>

using namespace std;

char s[10005];
int num[105];

int gcd(int a, int b) {return b == 0 ? a : gcd(b, a%b);}

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        memset(num, 0, sizeof(num));
        int cnt = 0;
        gets(s);
        int tmp = 0;
        for(int i = 0; i < strlen(s); i++)
        {
            if(s[i] != ' ')
            {
                tmp = 0;
                for(; s[i] <= '9' && s[i] >= '0'; i++)
                    tmp = tmp*10 + s[i]-'0';
            }
            num[cnt++] = tmp;
        }
        //printf("%s\n", s);
        int ans = 0;
        for(int i = 0; i < cnt; i++)
        {
            for(int j = i+1; j < cnt; j++)
            {
                //cout<<num[i]<<" "<<num[j]<<endl;
                ans = max(ans, gcd(num[i], num[j]));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
 */