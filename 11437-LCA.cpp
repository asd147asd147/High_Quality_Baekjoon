#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<vector<int>> tree(50001);
int dp[18][50001];
int depth[50001] = {-1,};

int LCA(int v, int u){
    if(depth[v] < depth[u]){
        swap(v,u);
    }
    for(int i = 17; i >= 0; i--){
        if(depth[dp[i][v]] >= depth[u]) v = dp[i][v];
    }
    if(v == u) return v;
    for(int i = 17; i >= 0; i--){
        if(dp[i][u] != dp[i][v]){
            v = dp[i][v], u = dp[i][u];
        }
    }
    return dp[0][v];
}

void makeTree(int cur, int par){
    depth[cur] = depth[par]+1;
    dp[0][cur] = par;
    for(int i = 1; i <= 17; i++){
        dp[i][cur] = dp[i-1][dp[i-1][cur]];
    }
    for(auto t : tree[cur]){
        if(t != par){
            makeTree(t, cur);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }
    makeTree(1,0);
    cin >> M;
    for(int i = 0; i < M; i++){
        int v,u;
        cin >> v >> u;
        cout << LCA(v,u) << "\n";
    }
	return 0;
}
