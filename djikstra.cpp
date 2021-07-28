#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
vector<pair<int, int>> adj[1000];
vector<int>d;
vector<int>p;
int n, m;
int a, b, l;
void djikstra(int s, vector<int> & d, vector<int> & p) {
    ///int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    set<pair<int, int>>q;
    q.insert({0, s});
    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
                p[to] = v;
            }
        }
    }
}
vector<int> restore_path(int s, int t, vector<int> const& p) {
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}
int main() {
cin >> n >> m;
for(int i=0; i<m; ++i)
{
    cin >> a >> b >> l;
    adj[a].push_back({b, l});
    adj[b].push_back({a, l});
}
djikstra(0, d, p);
cout << d[5];
return 0;
}
/**
6 9
0 1 4
0 2 2
1 2 1
1 3 5
2 3 8
2 4 10
3 4 2
3 5 6
4 5 5
**/
