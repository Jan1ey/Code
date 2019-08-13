#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m, k;
    cin>>n>>m>>k;
    long long op = 1, page = 0, del = 0, num;
    cin>>page;
    page = (page-1)/k+1;
    for(int i = 2; i <= m; i++)
    {
        cin>>num;
        if((num-del-1)/k+1 > page)
        {
            del = i-1;
            page = (num-del-1)/k+1;
            op++;
        }
    }
    cout<<op<<endl;
    return 0;
}
