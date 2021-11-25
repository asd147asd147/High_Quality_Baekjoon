#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N;

vector<int> adj[53];
int capacity[53][53];
int flow[53][53];

int ctoi(char c){
    if(c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

int main(){
    int ans = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	memset(capacity,0,sizeof(capacity));
	memset(flow,0,sizeof(flow));

	for(int i = 0; i < N; i++){
        char a,b;
        int a_i, b_i, c;
        cin >> a >> b >> c;
        a_i = ctoi(a);
        b_i = ctoi(b);
        adj[a_i].push_back(b_i);
        adj[b_i].push_back(a_i);
        capacity[a_i][b_i] += c;
        capacity[b_i][a_i] += c;
	}
	while(1){
        queue<int> q;
        int prev[53];
        memset(prev, -1, sizeof(prev));

        q.push(0);
        while(!q.empty()){
            int p = q.front();
            q.pop();
            if(p == 25){
                break;
            }
            for(auto a : adj[p]){
                if(prev[a] == -1 && capacity[p][a] - flow[p][a] > 0){
                    q.push(a);
                    prev[a] = p;
                }
            }
        }

        if(prev[25] == -1) break;

        int minFlow = INF;
        for(int i = 25; i != 0; i = prev[i]){
            minFlow = min(minFlow, capacity[prev[i]][i] - flow[prev[i]][i]);
        }

        for(int i = 25; i != 0; i = prev[i]){
            flow[prev[i]][i] += minFlow;
            flow[i][prev[i]] -= minFlow;
        }
        ans += minFlow;
	}
	cout << ans;

	return 0;
}
