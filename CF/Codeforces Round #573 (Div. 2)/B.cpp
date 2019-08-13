#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y, z;
    char a, b,c;
    scanf("%d%c %d%c %d%c", &x, &a, &y, &b, &z, &c);
    if(x > y)
    {
        swap(x, y);
        swap(a, b);
    }
    if(y > z)
    {
        swap(y, z);
        swap(b, c);
    }
    if(x > y)
    {
        swap(x, y);
        swap(a, b);
    }
    if(x == y && y == z && a == b && b == c)
        puts("0");
    else if(x+1 == y && y+1 == z && a == b && b == c)
        puts("0");
    else if(x == y && a == b)
        puts("1");
    else if(y == z && b == c)
        puts("1");
    else if(x+1 == y && a == b)
        puts("1");
    else if(x+1 == z && a == c)
        puts("1");
    else if(y+1 == z && b == c)
        puts("1");
    else if(x+2 == y && a == b)
        puts("1");
    else if(x+2 == z && a == c)
        puts("1");
    else if(y+2 == z && b == c)
        puts("1");
    else puts("2");
    //cout<<x<<a<<" "<<y<<b<<" "<<z<<c<<endl;
    return 0;
}
