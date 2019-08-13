//
// Created by mile on 2019/7/26.
//
// 离散化点+Floyd

#include <bits/stdc++.h>

#define ps push
#define pb push_back
#define mp make_pair

using namespace std;

vector<pair<long long, pair<int, int>>> edges;
vector<int> ver;
long long dis[1005][1005];

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edges.pb(mp(w, mp(u, v)));
    }
    sort(edges.begin(), edges.end());
    for(int i = 0; i < min(m, k); ++i) {
        ver.pb(edges[i].second.first);
        ver.pb(edges[i].second.second);
    }
    sort(ver.begin(), ver.end());
    ver.erase(unique(ver.begin(), ver.end()), ver.end());
    int sz = ver.size();
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 0; i <= sz; i++) {
        dis[i][i] = 0;
    }

    for(int i = 0; i < min(m, k); i++) {
        int x = lower_bound(ver.begin(), ver.end(), edges[i].second.first)-ver.begin();
        int y = lower_bound(ver.begin(), ver.end(), edges[i].second.second)-ver.begin();
        dis[x][y] = dis[y][x] = min(dis[x][y], edges[i].first);
    }
    vector<long long> ans;
    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
            for(int k = 0; k < sz; k++) {
                dis[j][k] = min(dis[j][k], dis[j][i]+dis[i][k]);
            }
        }
    }
    for(int i = 0; i < sz; i++) {
        for(int j = i+1; j < sz; j++) {
            ans.pb(dis[i][j]);
        }
    }
    sort(ans.begin(), ans.end());
    printf("%lld\n", ans[k-1]);
    return 0;
}
