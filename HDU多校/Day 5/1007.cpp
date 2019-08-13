//-----------------------------------------------
//code by mile
//compiled by clion
//no bug
//Always get ACCEPT
//-----------------------------------------------

#include <bits/stdc++.h>

#define pb push_back
#define emp emplace_back
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 100005;
int sta, ed, n, ans;
int vis[maxn];

void dfs(int x, int cnt) {
	//cout<<x<<endl;
	if(x > n) return;
	if(!vis[x]) vis[x] = 1;
	else return ;
	if(cnt == n-2 && abs(x-ed) <= 2) {
		//cout<<"ans"<<endl;
		ans++;
	}
	for(int i = 1; i <= n; i++) {
		if(i != sta && i != ed && !vis[i] && abs(i-x) <= 2) {
			dfs(i, cnt+1);
		}
	}
	return ;
}


int main() {
	while(cin>>n>>sta>>ed) {
		ans = 0;
		memset(vis, 0, sizeof(vis));
		vis[sta] = vis[ed] = 1;
		dfs(sta+1, 1);
		cout<<"1"<<" "<<ans<<endl;
		memset(vis, 0, sizeof(vis));
		vis[sta] = vis[ed] = 1;
		if(sta > 1) dfs(sta-1, 1);
		cout<<"2"<<" "<<ans<<endl;
		memset(vis, 0, sizeof(vis));
		vis[sta] = vis[ed] = 1;
		dfs(sta+2, 1);
		cout<<"3"<<" "<<ans<<endl;
		memset(vis, 0, sizeof(vis));
		vis[sta] = vis[ed] = 1;
		if(sta > 2) dfs(sta-2, 1);
		cout<<"4"<<" "<<ans<<endl;

		cout<<ans<<endl;
	}
	return 0;
}
