#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = n; ;i++)
    {
        int a = i/1000, b = i/100%10, c = i/10%10, d = i%10;
        if((a+b+c+d)%4==0)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
