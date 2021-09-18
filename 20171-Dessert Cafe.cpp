#include <bits/stdc++.h>

using namespace std;

int N, K;

vector<vector<int>> vec;
int ans = 0;
int apt[100001] = {0,};
int visited[100001] = {0,};

int dfs(int node){
    visited[node] = 1;
    int cnt = apt[node];
    for(auto v : vec[node]){
        if(visited[v]) continue;
        cnt += dfs(v);
    }
    if(cnt >= 1 || apt[node]){
        ans++;
    }
    return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	vec.resize(N+1);
	for(int i = 0; i < N-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back(b);
        vec[b].push_back(a);
	}
	int init;
	for(int i = 0; i < K; i++){
        int k;
        cin >> k;
        apt[k] = 1;
        init = k;
	}

	dfs(init);
    cout << ans;
	return 0;
}
