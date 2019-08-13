#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;
set<string> se;

bool BFS(string s)
{
    queue<string> qe;
    qe.push(s);
    se.insert(s);
    if(se.size() == k) return true;
    while(!qe.empty())
    {
        string now = qe.front();
        qe.pop();
        for(int i = 0; i < now.size(); i++)
        {
            string tmp = now;
            string nx = tmp.erase(i, 1);
            if(se.count(nx)) continue;
            else
            {
                qe.push(nx);
                se.insert(nx);
            }
            if(se.size() == k) return true;
        }
    }
    return false;
}

int main()
{
    cin>>n>>k;
    cin>>s;
    if(BFS(s))
    {
        int ans = 0;
        for(auto it : se)
        {
            ans += s.size()-it.size();
        }
        cout<<ans<<endl;
    }
    else cout<<-1<<endl;
    return 0;
}
