#include <bits/stdc++.h>
using namespace std;
vector<vector<int> >adj;
vector<vector<int> >up;
vector<int> tin, tout;
int n, l;
int timer=0;
void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0]=p;
    for(int i=0; i<=l; ++i)
    {
        up[v][i]=up[up[v][i-1]][i-1];
    }
    for(int u : adj[v])
    {
        if(u!=p)
        {
            dfs(u, v);
        }
    }
    tout[v] = ++timer;
}
bool is_ansestor(int u, int v)
{
    return tin[u]<=tin[v] && tout[u]>=tout[v];
}
int lca(int u, int v)
{
    if(is_ansestor(u, v))
    {
        return u;
    }
    if(is_ansestor(v, u))
    {
        return v;
    }
    for(int i=l; i>=0; i--)
    {
        if(!is_ansestor(up[u][i], v))
        {
            u=up[u][i];
        }
    }
    return up[u][0];
}
void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}
int main(){
///тук следва въвеждане и тестване

return 0;
}

