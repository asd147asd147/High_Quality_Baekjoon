#include <bits/stdc++.h>

using namespace std;

int N;

vector<vector<int>> vec;
int dp[1000001][2];
int visited[1000001] = {0, };

void early(int idx){
    visited[idx] = 1;
    dp[idx][0] = 1;

    for(auto v : vec[idx]){
        if(visited[v]) continue;
        early(v);
        dp[idx][1] += dp[v][0];
        dp[idx][0] += min(dp[v][1], dp[v][0]);
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	vec.resize(N+1);
	for(int i = 0; i < N-1; i++){
        int start, finish;
        cin >> start >> finish;
        vec[start].push_back(finish);
        vec[finish].push_back(start);
	}

	early(1);
	cout << min(dp[1][0],dp[1][1]);

	return 0;
}
