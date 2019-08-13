//
// Created by mile on 2019/7/20.
//
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x, a, y, b;
    while(cin>>x>>a>>y>>b){
        int ans1 = x/a, ans2 = y/b;
        if(ans1 > ans2) cout<<">"<<endl;
        else if(ans1 < ans2) cout<<"<"<<endl;
        else
        {
            x %= a, y %= b;
            if(x*b < y*a) cout<<"<"<<endl;
            else if(x*b == y*a) cout<<"="<<endl;
            else cout<<">"<<endl;
        }
    }
    return 0;
}