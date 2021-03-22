#include <bits/stdc++.h>

using namespace std;

void solve(){
    int cost[1001];
    int sum_cost[1001] = {0,};
    int t[1001] = {0,};
    int N, K, W;
    cin >> N >> K;
    vector<vector<int>> graph(N+1);
    for(int i = 1; i <= N; i++)
        cin >> cost[i];

    for(int i = 0; i < K; i++){
        int a,b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        t[b]++;
    }
    cin >> W;
    queue<int> q;
    for(int i = 1; i <= N; i++){
        if(!t[i]){
            q.push(i);
            sum_cost[i] = cost[i];
        }
    }
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        if(p == W){
            cout << sum_cost[p] << "\n";
            return;
        }
        for(auto g : graph[p]){
            t[g]--;
            sum_cost[g] = max(sum_cost[g], sum_cost[p] + cost[g]);
            if(!t[g]){
                q.push(g);
            }
        }
    }
    cout << cost[W] << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
        solve();
	}
	return 0;
}
