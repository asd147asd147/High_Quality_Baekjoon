#include <bits/stdc++.h>

using namespace std;

int N,M;
bool visited[40001] = {0,};
int depth[40001];
int dist[40001];
int dp[40001][20];
vector<vector<pair<int,int>>> vec;

void make_tree(int now, int d, int c){
    visited[now] = 1;
    depth[now] = d;
    dist[now] = c;
    for(auto v : vec[now]){
        if(visited[v.first]) continue;
        dp[v.first][0] = now;
        make_tree(v.first, d+1, c+v.second);
    }
}

int LCA(int a, int b){
    if(depth[a] < depth[b]) swap(a,b);
    int diff = depth[a] - depth[b];
    for(int i = 0; diff; i++){
        if(diff & 1) a = dp[a][i];
        diff >>= 1;
    }
    if(a==b) return a;
    for(int i = 19; i >= 0; i--){
        if(dp[a][i] != dp[b][i]) a = dp[a][i], b = dp[b][i];
    }
    return dp[a][0];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	vec.resize(N+1);
	for(int i = 0; i < N-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({b,c});
        vec[b].push_back({a,c});
	}
	dp[1][0] = 0; visited[1] = 1;
	make_tree(1,0,0);
	for(int j = 1; j < 20; j++){
        for(int i = 1; i <= N; i++){
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
	}
	cin >> M;
	for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        cout << dist[a] + dist[b] - 2*dist[LCA(a,b)] << "\n";
	}

	return 0;
}
