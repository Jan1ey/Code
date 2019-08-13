#include <bits/stdc++.h>

using namespace std;

int maps[105][105];

int main()
{
    int n, k;
    cin>>n>>k;
    if(k > n*n)
    {
        cout<<-1<<endl;
        return 0;
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = i; j <= n; j++)
            {
                if(i == j)
                {
                    if(k >= 1) maps[i][j] = 1, k--;
                }
                else
                {
                    if(k >= 2) maps[i][j]=maps[j][i]=1, k-=2;
                }
            }
        }
        if(k == 0)
        {
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= n; j++)
                {
                    cout<<maps[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}
