#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> adj[100005];
int depth[100005];
int parent[100005][18];

void dfs(int idx){
    for(auto& i : adj[idx]){
        if(depth[i]==-1){
            depth[i] = depth[idx] + 1;
            parent[i][0] = idx;
            dfs(i);
        }
    }
}
inline void LCA(int& a, int& b){
    if(a!=b){
        for(int i=17;i>=0;i--){
            if(parent[a][i]!=parent[b][i]){
                a = parent[a][i];
                b = parent[b][i];
            }
        }
        a = parent[a][0];
    }
    cout << a+1 << '\n';
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(depth,-1,sizeof(depth));
    memset(parent,-1,sizeof(parent));
    depth[0] = 0;
    dfs(0);
    for(int k=0;k<17;k++){
        for(int i=0;i<n;i++){
            if(parent[i][k]==-1) continue;
            parent[i][k+1] = parent[parent[i][k]][k];
        }
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        u--,v--;
        if(depth[u]<depth[v]) swap(u,v);
        int diff = depth[u]-depth[v];
        for(int i=0;diff!=0;i++){
            if(diff%2==1) u = parent[u][i];
            diff/=2;
        }
        LCA(u,v);
    }
    return 0;
}