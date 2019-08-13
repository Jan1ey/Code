//
// Created by mile on 2019/7/20.
//
#include <bits/stdc++.h>

using namespace std;

__int128 ans1, ans2;

int main()
{
    long long x, a, y, b;
    while(cin>>x>>a>>y>>b){
        ans1 = b, ans2 = a;
        ans1 *= x, ans2 *= y;
        if(ans1 == ans2) cout<<"="<<endl;
        else if(ans1 < ans2) cout<<"<"<<endl;
        else cout<<">"<<endl;
    }
    return 0;
}
