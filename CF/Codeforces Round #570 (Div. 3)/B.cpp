#include <bits/stdc++.h>

using namespace std;

vector<int> ve;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++)
        {
            int a;
            cin>>a;
            ve.push_back(a);
        }
        sort(ve.begin(), ve.end());
        int flag = 1;
        long long ans = ve[0]+k;
        for(auto it : ve)
        {
            if(abs(it-ans) <= k) continue;
            else
            {
                //cout<<it<<" "<<k<<endl;
                flag = 0;
                break;
            }
        }
        if(!flag) printf("-1\n");
        else printf("%lld\n", ans);
        ve.clear();
    }
    return 0;
}
