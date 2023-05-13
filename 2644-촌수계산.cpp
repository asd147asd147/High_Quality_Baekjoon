#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, a, b, M;
	cin >> N >> a >> b >> M;

	int adj[101][101];
	bool visited[101] = {0, };
	for(int i = 0; i < M; i++){
        int c, d;
        cin >> c >> d;
        adj[c][d] = adj[d][c] = 1;
	}

	queue<int> q;
	q.push(a);
	visited[a] = true;

	int degree = 0;

	while(!q.empty()){
        int s = q.size();
        degree++;
        for(int i = 0; i < s; i++){
            auto p = q.front();
            q.pop();
            for(int i = 1; i < 101; i++){
                if(i == b && adj[p][i] == 1){
                    cout << degree;
                    return 0;
                }
                if(adj[p][i] && !visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
	}
	cout << -1;
	return 0;
}
