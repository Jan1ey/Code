#include <bits/stdc++.h>

using namespace std;

int n, m;
int maps[105][105];
int ct[105];

int main()
{
    cin>>n>>m;
    for(int i = 1; i <= n; i++) ct[i] = INT_MAX;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin>>maps[i][j];
            ct[i] = min(maps[i][j], ct[i]);
        }
    }
    sort(ct+1, ct+n+1);
    cout<<ct[n]<<endl;
    return 0;
}
