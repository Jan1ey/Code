//
// Created by mile on 2019/7/24.
//

#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
using namespace std;

vector<pair<int, int> > ans;

int main()
{
    int q;
    scanf("%d", &q);
    while(q--) {
        int b, w;
        int x, y;
        x = y = 1000000;
        scanf("%d%d", &b, &w);
        if(b < w) swap(b, w), x++;
        for(int i = 0; i < w; i++) {
            ans.pb(mp(x+i*2, y));
            if(b) {
                ans.pb(mp(x+i*2+1, y));
                b--;
            }
        }
        for(int i = 0; i < w; i++) {
            if(b) {
                ans.pb(mp(x+i*2,y+1)); b--;
            }
            if(b) {
                ans.pb(mp(x+i*2, y-1)); b--;
            }
        }
        if(b) ans.pb(mp(x-1, y)), b--;
        //if(b) ans.pb(mp(x+2*w-1, y)), b--;
        if(b != 0) {
            puts("NO");
        } else {
            puts("YES");
            for(auto it : ans) {
                printf("%d %d\n", it.first, it.second);
            }
        }
        ans.clear();
    }
    return 0;
}